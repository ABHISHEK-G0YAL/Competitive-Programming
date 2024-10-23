// https://leetcode.com/problems/palindromic-substrings/

class Solution {
public:
    int countSubstringsExpandCentre(string s) {
        int count = 0, n = s.length(), d = 1;
        for (int i = 0; i < n; i++) {
            d = 0;
            while (i - d >= 0 && i + d < n && s[i - d] == s[i + d]) {
                ++d;
                ++count;
            }
            d = 0;
            while (i - d >= 0 && i + 1 + d < n && s[i - d] == s[i + 1 + d]) {
                ++d;
                ++count;
            }
        }
        return count;
    }

    int countSubstringsDP(string s) {
        int count = 0, n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n));
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
            ++count;
            if (i + 1 < n && s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                ++count;
            }
        }
        for (int l = 3; l <= n; l++) {
            for (int i = 0, j = l - 1; j < n; ++i, ++j) {
                dp[i][j] = dp[i + 1][j - 1] && s[i] == s[j];
                count += dp[i][j];
            }
        }
        return count;
    }

    int countSubstrings(string s) {
        // 2 ms Beats 95.72%
        return countSubstringsExpandCentre(s);

        // 50 ms Beats 22.49%
        // return countSubstringsDP(s);
    }
};