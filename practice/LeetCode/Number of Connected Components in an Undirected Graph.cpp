// https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/
// https://www.lintcode.com/problem/3651/

class Solution {
public:
    void dfs(vector<vector<int>> &adj, vector<bool> &visited, int v) {
        visited[v] = true;
        for (auto u : adj[v]) {
            if (!visited[u]) {
                dfs(adj, visited, u);
            }
        }
    }

    /**
     * @param n: the number of vertices
     * @param edges: the edges of undirected graph
     * @return: the number of connected components
     */
    int countComponents(int n, vector<vector<int>> &edges) {
        vector<vector<int>> adj(n);
        for (auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int count = 0;
        vector<bool> visited(n);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                ++count;
                dfs(adj, visited, i);
            }
        }
        return count;
    }
};