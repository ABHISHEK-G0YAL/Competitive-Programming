// https://leetcode.com/problems/minimum-path-sum/

class Solution {
public:
    // 0 ms Beats 100.00%
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        for (int j = 1; j < m; j++) {
            grid[0][j] += grid[0][j - 1];
        }
        for (int i = 1; i < n; i++) {
            grid[i][0] += grid[i - 1][0];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                grid[i][j] += min(grid[i][j - 1], grid[i - 1][j]);
            }
        }
        return grid.back().back();
    }
};