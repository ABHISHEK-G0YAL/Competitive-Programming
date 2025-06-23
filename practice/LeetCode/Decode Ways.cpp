// https://leetcode.com/problems/decode-ways/

class Solution {
public:
    int numDecodings(string &s, int i = 0) {
        // if (i == s.length()) {
        //     return 1;
        // }
        // int decodings = 0;
        // if (s[i] != '0') {
        //     decodings += numDecodings(s, i + 1);
        // } else {
        //     return 0;
        // }
        // if (i + 1 < s.length() && (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))) {
        //     decodings += numDecodings(s, i + 2);
        // }
        // return decodings;

        int n = s.length();
        vector<int> dp(n + 1);
        dp[n] = 1;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') {
                dp[i] = 0;
            } else {
                dp[i] += dp[i + 1];
                if (i + 1 < s.length() && (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))) {
                    dp[i] += dp[i + 2];
                }
            }
        }
        return dp[0];
    }
};