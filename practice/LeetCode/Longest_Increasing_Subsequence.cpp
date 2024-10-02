// https://leetcode.com/problems/longest-increasing-subsequence/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int i = 0, int j = -1) {
        // if (i == nums.size()) {
        //     return 0;
        // }
        // int ans = 0;
        // if (j == -1 || nums[i] > nums[j]) {
        //     ans = 1 + lengthOfLIS(nums, i + 1, i);
        // }
        // ans = max(ans, lengthOfLIS(nums, i + 1, j));
        // return ans;


        int n = nums.size();
        vector<int> dp(n, 1);
        dp[0] = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};