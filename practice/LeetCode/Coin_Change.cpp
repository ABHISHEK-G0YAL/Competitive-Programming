// https://leetcode.com/problems/coin-change/

class Solution {
public:
    long coinChangeHelper(vector<int>& coins, int amount, int i = 0) {
        // if (amount == 0) {
        //     return 0;
        // }
        // if (i == coins.size()) {
        //     return INT_MAX;
        // }
        // if (coins[i] <= amount) {
        //     return min(
        //         1 + coinChangeHelper(coins, amount - coins[i], i)
        //         , coinChangeHelper(coins, amount, i + 1)
        //     );
        // }
        // return coinChangeHelper(coins, amount, i + 1);

        vector<vector<long>> dp(amount + 1, vector<long> (coins.size() + 1, INT_MAX));
        dp[0] = vector<long> (coins.size() + 1, 0);
        for (int am = 1; am <= amount; am++) {
            for (int i = coins.size() - 1; i >= 0; i--) {
                if (coins[i] <= am) {
                    dp[am][i] = min(1 + dp[am - coins[i]][i], dp[am][i + 1]);
                } else {
                    dp[am][i] = dp[am][i + 1];
                }
            }
        }
        return dp[amount][0];
    }

    int coinChange(vector<int>& coins, int amount) {
        int minCoins = coinChangeHelper(coins, amount);
        return minCoins < INT_MAX ? minCoins : -1;
    }
};