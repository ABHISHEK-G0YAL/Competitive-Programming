// https://leetcode.com/problems/coin-change/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp = vector<int> (amount + 1);
        for(int amt = 1; amt <= amount; amt += 1) {
            dp[amt] = INT_MAX - 1;
            for(int &coin : coins)
                if(coin <= amt)
                    dp[amt] = min(dp[amt], 1 + dp[amt - coin]);
        }
        return dp[amount] == INT_MAX - 1 ? -1 : dp[amount];
    }
};