// https://leetcode.com/problems/longest-common-subsequence/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2, int i = 0, int j = 0) {
        // if (i == text1.length()) {
        //     return 0;
        // }
        // if (j == text2.length()) {
        //     return 0;
        // }
        // if (text1[i] == text2[j]) {
        //     return 1 + longestCommonSubsequence(text1, text2, i + 1, j + 1);
        // } else {
        //     return max(
        //         longestCommonSubsequence(text1, text2, i + 1, j),
        //         longestCommonSubsequence(text1, text2, i, j + 1)
        //     );
        // }

        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][m];
    }
};