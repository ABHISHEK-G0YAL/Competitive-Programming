// https://leetcode.com/problems/longest-palindromic-subsequence/

class Solution {
public:
    // NxN space | 2D DP
    // 62 ms Beats 60.60%
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
            if (i + 1 < n) {
                dp[i][i + 1] = s[i] == s[i + 1] ? 2 : 1;
            }
        }
        for (int l = 3; l <= n; ++l) {
            for(int i = 0, j = l - 1; j < n; ++i, ++j) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
                }
            }
        }
        return dp[0][n - 1];
    }

    // 3N space (without using move() uses same space as 2D DP)
    // 28 ms Beats 95.87%
    int longestPalindromeSubseqOptimised(string s) {
        int n = s.length();
        // vector<vector<int>> dp(n, vector<int>(n, 0));
        if (s.length() < 2) {
            return s.length();
        }
        vector<int> ln2(n), ln1(n), ln(n);
        for (int i = 0; i < n; i++) {
            ln2[i] = 1;
            if (i + 1 < n) {
                ln1[i + 1] = s[i] == s[i + 1] ? 2 : 1;
            }
        }
        for (int l = 3; l <= n; ++l) {
            for(int i = 0, j = l - 1; j < n; ++i, ++j) {
                if (s[i] == s[j]) {
                    ln[j] = ln2[j - 1] + 2;
                } else {
                    ln[j] = max(ln1[j - 1], ln1[j]);
                }
            }
            vector<int> temp = move(ln2);
            ln2 = move(ln1);
            ln1 = move(ln);
            ln = move(temp);
        }
        return ln1.back();
    }
};