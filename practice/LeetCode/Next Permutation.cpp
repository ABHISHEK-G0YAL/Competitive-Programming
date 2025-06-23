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

                // // O(nlog(n))
                // sort(nums.begin() + i + 1, nums.end());

                // O(n)
                // Reverse instead of sorting, as it's already in reverse order
                reverse(nums.begin() + i + 1, nums.end());
                break;
            }
            --i;
        }
        if (i < 0) {
            // // O(nlog(n))
            // sort(nums.begin(), nums.end());

            // O(n)
            // Reverse instead of sorting, as it's already in reverse order
            reverse(nums.begin() + i + 1, nums.end());
        }
    }
};