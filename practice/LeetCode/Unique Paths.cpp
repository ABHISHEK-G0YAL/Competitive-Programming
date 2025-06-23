// https://leetcode.com/problems/unique-paths/

class Solution {
public:
    int uniquePaths(int m, int n) {
        // if (m == 1 && n == 1) {
        //     return 1;
        // }
        // if (m == 1) {
        //     return uniquePaths(m, n - 1);
        // }
        // if (n == 1) {
        //     return uniquePaths(m - 1, n);
        // }
        // return uniquePaths(m, n - 1) + uniquePaths(m - 1, n);

        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};