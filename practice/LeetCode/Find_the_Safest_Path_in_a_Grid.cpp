class SolutionA {
public:
    static int getMaxMinDistBacktracking(vector<vector<int>> &grid, int i, int j, vector<vector<bool>> &visited) {
        int n = grid.size();
        if (i < 0 || j < 0 || i == n || j == n || visited[i][j]) {
            return -1;
        }
        if (i == n - 1 && j == n - 1) {
            return grid[i][j];
        }
        visited[i][j] = true;
        int dist1 = -1, dist2 = -1, dist3 = -1, dist4 = -1;
        if (i + 1 < n) {
            dist1 = getMaxMinDistBacktracking(grid, i + 1, j, visited);
        }
        if (i - 1 >= 0) {
            dist2 = getMaxMinDistBacktracking(grid, i - 1, j, visited);
        }
        if (j + 1 < n) {
            dist3 = getMaxMinDistBacktracking(grid, i, j + 1, visited);
        }
        if (j - 1 >= 0) {
            dist4 = getMaxMinDistBacktracking(grid, i, j - 1, visited);
        }
        visited[i][j] = false;
        int maxDist = max({dist1, dist2, dist3, dist4});
        return maxDist != -1 ? min(grid[i][j], maxDist) : -1;
    }

    static void fillDistance(vector<vector<int>> &grid) {
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool> (n, false));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }
        int dist = 0;
        vector<pair<int,int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!q.empty()) {
            int q_size = q.size();
            while (q_size--) {
                auto [i, j] = q.front();
                q.pop();
                grid[i][j] = dist;
                for (auto [x, y] : direction) {
                    int io = i + x;
                    int jo = j + y;
                    if (io >= 0 && io < n && jo >= 0 && jo < n && !visited[io][jo]) {
                        visited[io][jo] = true;
                        q.push({io, jo});
                    }
                }

            }
            ++dist;
        }
    }

    static int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        // Multi source BFS
        fillDistance(grid);

        // DFS with backtracking (slow) - TLE (528 / 1036 testcases passed)
        vector<vector<bool>> visited(n, vector<bool> (n, false));
        return getMaxMinDistBacktracking(grid, 0, 0, visited);
    }
};

class SolutionB {
public:
    static bool checkMinDistPossibleDfs(vector<vector<int>> &grid, int i, int j, vector<vector<bool>> &visited, int minDist) {
        int n = grid.size();
        if (i < 0 || j < 0 || i == n || j == n || visited[i][j] || grid[i][j] < minDist) {
            return false;
        }
        if (i == n - 1 && j == n - 1) {
            return true;
        }
        visited[i][j] = true;
        return checkMinDistPossibleDfs(grid, i + 1, j, visited, minDist) ||
            checkMinDistPossibleDfs(grid, i - 1, j, visited, minDist) ||
            checkMinDistPossibleDfs(grid, i, j + 1, visited, minDist) ||
            checkMinDistPossibleDfs(grid, i, j - 1, visited, minDist);
    }

    static int fillDistance(vector<vector<int>> &grid) {
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool> (n, false));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }
        int dist = 0;
        vector<pair<int,int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!q.empty()) {
            int q_size = q.size();
            while (q_size--) {
                auto [i, j] = q.front();
                q.pop();
                grid[i][j] = dist;
                for (auto [x, y] : direction) {
                    int io = i + x;
                    int jo = j + y;
                    if (io >= 0 && io < n && jo >= 0 && jo < n && !visited[io][jo]) {
                        visited[io][jo] = true;
                        q.push({io, jo});
                    }
                }

            }
            ++dist;
        }
        return dist;
    }

    static int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        // Multi source BFS
        int maxDist = fillDistance(grid), minDist = 0, ans = 0;

        // Using DFS and binary search
        while (minDist <= maxDist) {
            int mid = (maxDist + minDist) / 2;
            vector<vector<bool>> visited(n, vector<bool> (n, false));

            //  DFS without backtracking (still slow) - TLE (1032 / 1036 testcases passed)
            if (checkMinDistPossibleDfs(grid, 0, 0, visited, mid)) {
                ans = mid;
                minDist = mid + 1;
            } else {
                maxDist = mid - 1;
            }
        }
        return ans;
    }
};

class SolutionC {
public:
    static bool checkMinDistPossibleBfs(vector<vector<int>> &grid, int minDist) {
        int n = grid.size();
        queue<pair<int, int>> q;
        vector<pair<int, int>> direction = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        if (grid[0][0] >= minDist) {
            q.push({0, 0});
            visited[0][0] = true;
        }
        while(!q.empty()) {
            auto [i, j] = q.front();
            if (i == n - 1 && j == n - 1) {
                return true;
            }
            q.pop();
            for (auto[di, dj] : direction) {
                int ni = i + di, nj = j + dj;
                if (ni >= 0 && nj >= 0 && ni < n && nj < n && !visited[ni][nj] && grid[ni][nj] >= minDist) {
                    q.push({ni, nj});
                    visited[ni][nj] = true;
                }
            }
        }
        return false;
    }

    static int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

         // Multi source BFS
        int maxDist = SolutionB::fillDistance(grid), minDist = 0, ans = 0;

        // Using BFS and binary search
        while (minDist <= maxDist) {
            int mid = (maxDist + minDist) / 2;

            // BFS - AC (Beats 30%)
            if (checkMinDistPossibleBfs(grid, mid)) {
                ans = mid;
                minDist = mid + 1;
            } else {
                maxDist = mid - 1;
            }
        }
        return ans;
    }
};

class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        // return SolutionA::maximumSafenessFactor(grid);
        // return SolutionB::maximumSafenessFactor(grid);
        return SolutionC::maximumSafenessFactor(grid);
    }
};