// https://leetcode.com/problems/house-robber/

class Solution {
public:
    int rob(vector<int>& nums) {
        int maxSecondLastHouse = 0; // represents dp[i - 2]
        int maxLastHouseMoney = 0; // represents dp[i - 1]
        for (int i = 0; i < nums.size(); i++) {
            int maxCurrentHouseMoney = max(maxLastHouseMoney, maxSecondLastHouse + nums[i]);
            maxSecondLastHouse = maxLastHouseMoney;
            maxLastHouseMoney = maxCurrentHouseMoney;
        }
        return maxLastHouseMoney;  // dp[n - 1]
    }
};