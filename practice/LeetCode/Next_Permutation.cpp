// https://leetcode.com/problems/next-permutation/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;
        while (i >= 0) {
            if (nums[i] < nums[i + 1]) {
                int j = n - 1;
                while (nums[j] <= nums[i]) {
                    --j;
                }
                swap(nums[i], nums[j]);
                sort(nums.begin() + i + 1, nums.end());
                break;
            }
            --i;
        }
        if (i < 0) {
            sort(nums.begin(), nums.end());
        }
    }
};