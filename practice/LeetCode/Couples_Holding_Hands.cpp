// https://leetcode.com/problems/couples-holding-hands/

class Solution {
public:
    void dfs(unordered_map<int, vector<int>> &adj, int i, unordered_map<int, bool> &visited) {
        visited[i] = true;
        for (int v : adj[i]) {
            if (!visited[v]) {
                dfs(adj, v, visited);
            }
        }
    }

    int getMinSwaps(vector<pair<int,int>>& rowPair) {
        unordered_map<int, vector<int>> adj;
        unordered_map<int, bool> visited;
        for (auto &[u, v] : rowPair) {
            adj[u].push_back(v);
            adj[v].push_back(u);
            visited[v] = false;
            visited[u] = false;
        }
        int rings = 0;
        for (auto &[i, vis] : visited) {
            if (!vis) {
                dfs(adj, i, visited);
                ++rings;
            }
        }
        return rowPair.size() - rings;
    }

    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        for (int &i : row) {
            i = i / 2;
        }
        vector<pair<int, int>> rowPair;
        for (int i = 0; i < n; i += 2) {
            if (row[i] != row[i + 1]) {
                rowPair.push_back({ row[i], row[i + 1] });
            }
        }
        return getMinSwaps(rowPair);
    }
};