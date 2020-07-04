// https://leetcode.com/problems/wildcard-matching/
// Accepted    20 ms

class Solution {
public:
    bool isMatch(string &s, string &p) {
        bool dp[s.length() + 1][p.length() + 1];
        dp[s.length()][p.length()] = true;
        for(int i = s.length() - 1; i >= 0; i--) dp[i][p.length()] = false;
        for(int j = p.length() - 1; j >= 0; j--) {
            if(p[j] == '*') dp[s.length()][j] = dp[s.length()][j + 1];
            else dp[s.length()][j] = false;
        }
        for(int i = s.length() - 1; i >= 0; i--) {
            for(int j = p.length() - 1; j >= 0; j--) {
                if(s[i] == p[j] or p[j] == '?')
                    dp[i][j] = dp[i + 1][j + 1];
                else if(p[j] == '*')
                    dp[i][j] = dp[i][j + 1] or dp[i + 1][j];
                else
                    dp[i][j] = false;
            }
        } return dp[0][0];
    }
};