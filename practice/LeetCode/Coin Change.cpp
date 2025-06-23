// https://leetcode.com/problems/coin-change/

class Solution {
public:
    long coinChangeHelper(vector<int>& coins, int amount) {
        // if (amount < 0) {
        //     return INT_MAX;
        // }
        // if (amount == 0) {
        //     return 0;
        // }
        // long minCoins = INT_MAX;
        // for (int coin : coins) {
        //     minCoins = min(minCoins, coinChangeHelper(coins, amount - coin));
        // }
        // return 1 + minCoins;

        vector<long> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int am = 1; am <= amount; am++) {
            for (int coin : coins) {
                if (am - coin >= 0) {
                    dp[am] = min(dp[am], 1 + dp[am - coin]);
                }
            }
        }
        return dp[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        long minCoins = coinChangeHelper(coins, amount);
        return minCoins < INT_MAX ? minCoins : -1;
    }
};