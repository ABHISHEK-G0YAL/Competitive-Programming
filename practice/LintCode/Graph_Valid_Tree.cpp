// https://www.lintcode.com/problem/178/

class Solution {
public:
    /**
     * @param n: An integer
     * @param edges: a list of undirected edges
     * @return: true if it's a valid tree, or false
     */

    void dfs(vector<vector<int>> &adj, vector<bool> &visited, int v) {
        visited[v] = true;
        for (auto u : adj[v]) {
            if (!visited[u]) {
                dfs(adj, visited, u);
            }
        }
    }

    bool validTree(int n, vector<vector<int>> &edges) {
        if (edges.size() != n - 1) {
            return false;
        }
        vector<vector<int>> adj(n);
        for (auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n);
        dfs(adj, visited, 0);
        for (auto visit : visited) {
            if (!visit) {
                return false;
            }
        }
        return true;
    }
};