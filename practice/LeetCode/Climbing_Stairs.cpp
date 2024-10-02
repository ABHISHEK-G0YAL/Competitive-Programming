// https://leetcode.com/problems/climbing-stairs/

class Solution {
public:
    int climbStairs(int n) {
        // if (n == 0 || n == 1) {
        //     return 1;
        // }
        // return climbStairs(n - 1) + climbStairs(n - 2);

        vector<int> dp(n + 1, 1);
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};