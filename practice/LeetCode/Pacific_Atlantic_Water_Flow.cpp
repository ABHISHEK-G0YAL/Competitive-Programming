// https://leetcode.com/problems/pacific-atlantic-water-flow/

// Island to Ocean DFS
// correct solution 112 / 113 passed (TLE) O((N x M) ^ 2) ~ O(N ^ 4)
class SolutionA {
public:
    static pair<bool, bool> isPacificAtlanticConnected(vector<vector<int>>& heights, int i, int j, vector<vector<bool>>& visited) {
        int n = heights.size(), m = heights[0].size();
        if (i < 0 || j < 0) {
            return { true, false };
        }
        if (i == n || j == m) {
            return { false, true };
        }
        visited[i][j] = true;
        pair<bool, bool> ans = { false, false };
        if (i - 1 < 0 || (!visited[i - 1][j] && heights[i - 1][j] <= heights[i][j])) {
            pair<bool, bool> isConnected = isPacificAtlanticConnected(heights, i - 1, j, visited);
            ans.first = ans.first || isConnected.first;
            ans.second = ans.second || isConnected.second;
        }
        if (i + 1 >= n || (!visited[i + 1][j] && heights[i + 1][j] <= heights[i][j])) {
            pair<bool, bool> isConnected = isPacificAtlanticConnected(heights, i + 1, j, visited);
            ans.first = ans.first || isConnected.first;
            ans.second = ans.second || isConnected.second;
        }
        if (j - 1 < 0 || (!visited[i][j - 1] && heights[i][j - 1] <= heights[i][j])) {
            pair<bool, bool> isConnected = isPacificAtlanticConnected(heights, i, j - 1, visited);
            ans.first = ans.first || isConnected.first;
            ans.second = ans.second || isConnected.second;
        }
        if (j + 1 >= m || (!visited[i][j + 1] && heights[i][j + 1] <= heights[i][j])) {
            pair<bool, bool> isConnected = isPacificAtlanticConnected(heights, i, j + 1, visited);
            ans.first = ans.first || isConnected.first;
            ans.second = ans.second || isConnected.second;
        }
        return ans;
    }

    static vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> coordinates;
        int n = heights.size(), m = heights[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                vector<vector<bool>> visited(n, vector<bool>(m, false));
                pair<bool, bool> isConnected = isPacificAtlanticConnected(heights, i, j, visited);
                if (isConnected.first && isConnected.second) {
                    coordinates.push_back({i, j});
                }
            }
        }
        return coordinates;
    }
};

// DP solution - WA not feasible (misses paths)
class SolutionB {
public:
    static vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        // state 0 - cannot visit any
        // state 1 - can visit pacific
        // state 2 - can visit atlantic
        // state 3 - can vist both

        dp[0] = vector<int> (m, 1);
        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (heights[i][j] >= heights[i - 1][j]) {
                    dp[i][j] |= dp[i - 1][j];
                }
                if (heights[i][j] >= heights[i][j - 1]) {
                    dp[i][j] |= dp[i][j - 1];
                }
            }
        }
        for (int i = 0; i < n; i++) {
            dp[i][m - 1] |= 2;
        }
        for (int j = 0; j < m; j++) {
            dp[n - 1][j] |= 2;
        }
        for (int i = n - 2; i >= 0; i--) {
            for (int j = m - 2; j >= 0; j--) {
                if (heights[i][j] >= heights[i + 1][j]) {
                    dp[i][j] |= dp[i + 1][j];
                }
                if (heights[i][j] >= heights[i][j + 1]) {
                    dp[i][j] |= dp[i][j + 1];
                }
            }
        }
        vector<vector<int>> coordinates;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dp[i][j] == 3) {
                    coordinates.push_back({i, j});
                }
            }
        }
        return coordinates;
    }
};

// Ocean to Island DFS AC - Beats 60 %
class SolutionC {
public:
    static void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int i, int j) {
        int n = heights.size(), m = heights[0].size();
        if (i < 0 || j < 0 || i >= n || j >= m || visited[i][j]) {
            return;
        }
        visited[i][j] = true;
        if (i - 1 < 0 || heights[i - 1][j] >= heights[i][j]) {
            dfs(heights, visited, i - 1, j);
        }
        if (i + 1 >= n || heights[i + 1][j] >= heights[i][j]) {
            dfs(heights, visited, i + 1, j);
        }
        if (j - 1 < 0 || heights[i][j - 1] >= heights[i][j]) {
            dfs(heights, visited, i, j - 1);
        }
        if (j + 1 >= m || heights[i][j + 1] >= heights[i][j]) {
            dfs(heights, visited, i, j + 1);
        }
    }

    static vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<bool>> isPacificConnected(n, vector<bool>(m, false));
        vector<vector<bool>> isAtlanticConnected(n, vector<bool>(m, false));
        for (int i = 0; i < n; ++i) {
            dfs(heights, isPacificConnected, i, 0);
            dfs(heights, isAtlanticConnected, i, m - 1);
            
        }
        for (int j = 0; j < m; ++j) {
            dfs(heights, isPacificConnected, 0, j);
            dfs(heights, isAtlanticConnected, n - 1, j);
        }
        vector<vector<int>> coordinates;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (isPacificConnected[i][j] && isAtlanticConnected[i][j]) {
                    coordinates.push_back({i, j});
                }
            }
        }
        return coordinates;
    }
};

// Ocean to Island BFS AC - Beats 52 %
class SolutionD {
public:
    static void performBFS(vector<vector<int>>& heights, queue<pair<int, int>> &q, vector<vector<bool>> &visited) {
        int n = heights.size(), m = heights[0].size();
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            vector<pair<int, int>> neighbours = {{i + 1, j}, {i - 1, j}, {i, j + 1}, {i, j - 1}};
            for (auto [io, jo] : neighbours) {
                if (io >= 0 && jo >= 0 && io < n && jo < m && !visited[io][jo] && heights[io][jo] >= heights[i][j]) {
                    q.push({io, jo});
                    visited[io][jo] = true;
                }
            }
        }
    }

    static vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<bool>> isPacificConnected(n, vector<bool>(m, false));
        vector<vector<bool>> isAtlanticConnected(n, vector<bool>(m, false));
        queue<pair<int, int>> pacificQueue;
        queue<pair<int, int>> atlanticQueue;
        for (int i = 0; i < n; ++i) {
            if (!isPacificConnected[i][0]) {
                pacificQueue.push({i, 0});
                isPacificConnected[i][0] = true;
            }
            if (!isAtlanticConnected[i][m - 1]) {
                atlanticQueue.push({i, m - 1});
                isAtlanticConnected[i][m - 1] = true;
            }
        }
        for (int j = 0; j < m; ++j) {
            if (!isPacificConnected[0][j]) {
                pacificQueue.push({0, j});
                isPacificConnected[0][j] = true;
            }
            if (!isAtlanticConnected[n - 1][j]) {
                atlanticQueue.push({n - 1, j});
                isAtlanticConnected[n - 1][j] = true;
            }
        }
        performBFS(heights, pacificQueue, isPacificConnected);
        performBFS(heights, atlanticQueue, isAtlanticConnected);

        vector<vector<int>> coordinates;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (isPacificConnected[i][j] && isAtlanticConnected[i][j]) {
                    coordinates.push_back({i, j});
                }
            }
        }
        return coordinates;
    }
};

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        // return SolutionA::pacificAtlantic(heights);
        // return SolutionB::pacificAtlantic(heights);
        return SolutionC::pacificAtlantic(heights);
        // return SolutionD::pacificAtlantic(heights);
    }
};