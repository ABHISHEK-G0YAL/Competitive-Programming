// https://leetcode.com/problems/3sum/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            if (i != 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int target = -nums[i];
            int j = i + 1, k = n - 1;
            while(j < k) {
                if (nums[j] + nums[k] > target) {
                    --k;
                } else if (nums[j] + nums[k] < target) {
                    ++j;
                } else {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    --k;
                    ++j;
                    while(j < n && nums[j - 1] == nums[j]) ++j;
                    while(k >= 0 && nums[k] == nums[k + 1]) --k;
                }
            }
        }
        return ans;
    }
};