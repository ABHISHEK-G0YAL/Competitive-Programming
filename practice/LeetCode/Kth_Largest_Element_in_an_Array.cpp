// https://leetcode.com/problems/kth-largest-element-in-an-array/
// Accepted    12 ms

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        nth_element(nums.begin(), nums.begin() + nums.size() - k, nums.end());
        return nums[nums.size() - k];
    }
};