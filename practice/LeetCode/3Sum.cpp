// https://leetcode.com/problems/3sum/

class Solution {
public:
    vector<vector<int>> triplets;
    void twoSum(vector<int>& nums, int l, int r, int target) {
        int sum, n = nums.size();
        while (l < r) {
            sum = nums[l] + nums[r];
            if (sum > target) {
                --r;
            } else if (sum < target) {
                ++l;
            } else {
                triplets.push_back({ -target, nums[l], nums[r] });
                while(r > 0 && nums[r] == nums[r - 1]) --r; --r;
                while(l < n - 1 && nums[l] == nums[l + 1]) ++l; ++l;
            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            twoSum(nums, i + 1, n - 1, -nums[i]);
        }
        return triplets;
    }
};