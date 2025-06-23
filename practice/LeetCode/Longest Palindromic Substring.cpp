// https://leetcode.com/problems/longest-palindromic-substring/

class Solution {
public:
    string longestPalindromeExpandCentre(string s) {
        int n = s.length(), d;
        string longestPalindrome;
        for (int i = 0; i < n; i++) {
            d = 0;
            while (i - d >= 0 && i + d < n && s[i - d] == s[i + d]) {
                if (2 * d + 1 > longestPalindrome.length()) {
                    longestPalindrome = s.substr(i - d, 2 * d + 1);
                }
                ++d;
            }
            d = 0;
            while (i - d >= 0 && i + 1 + d < n && s[i - d] == s[i + 1 + d]) {
                if (2 * d + 2 > longestPalindrome.length()) {
                    longestPalindrome = s.substr(i - d, 2 * d + 2);
                }
                ++d;
            }
        }
        return longestPalindrome;
    }

    string longestPalindromeDP(string s) {
        int n = s.length();
        string longestPalindrome = s.substr(0, 1);
        vector<vector<bool>> dp(n, vector<bool>(n));
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
            if (i + 1 < n && s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                if (longestPalindrome.size() < 2) {
                    longestPalindrome = s.substr(i, 2);
                }
            }
        }
        for (int l = 3; l <= n; l++) {
            for (int i = 0, j = l - 1; j < n; ++i, ++j) {
                if (dp[i + 1][j - 1] && s[i] == s[j]) {
                    dp[i][j] = true;
                    if (longestPalindrome.size() < l) {
                        longestPalindrome = s.substr(i, l);
                    }
                }
            }
        }
        return longestPalindrome;
    }

    string longestPalindrome(string s) {
        // 9 ms Beats 87.54%
        return longestPalindromeExpandCentre(s);
    
        // 221 ms Beats 26.35%
        // return longestPalindromeDP(s);
    }
};