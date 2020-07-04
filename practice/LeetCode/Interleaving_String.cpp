// https://leetcode.com/problems/interleaving-string/
// Accepted    0 ms

class Solution {
public:
    bool isInterleave(string &s1, string &s2, string &s3) {
        int n1 = s1.length(), n2 = s2.length(), n3 = s3.length();
        if(n1 + n2 != n3)
            return false;
        bool dp[n1 + 1][n2 + 1];
        memset(dp, 0, sizeof(dp));
        bool a1, a2;
        for(int i = 0; i <= n1; i++) {
            for(int j = 0; j <= n2; j++) {
                if(i + j == 0) {
                    dp[i][j] = true;
                    continue;
                }
                a1 = a2 = false;
                if(i - 1 >= 0 and s1[i - 1] == s3[i + j - 1])
                    a1 = dp[i - 1][j];
                if(j - 1 >= 0 and s2[j - 1] == s3[i + j - 1])
                    a2 = dp[i][j - 1];
                dp[i][j] = a1 or a2;
            }
        }
        return dp[n1][n2];
    }
};