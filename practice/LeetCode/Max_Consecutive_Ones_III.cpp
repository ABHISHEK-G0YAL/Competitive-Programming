// https://leetcode.com/problems/max-consecutive-ones-iii/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int count1 = 0, count0 = 0, l = 0, r = 0, n = nums.size(), maxCount = 0;
        while (l < n && r < n) {
            if (nums[r] == 1) {
                ++count1;
            } else {
                ++count0;
            }
            if (count0 > k) {
                while (nums[l]) {
                    ++l;
                }
                ++l;
                --count0;
            }
            maxCount = max(maxCount, r - l + 1);
            ++r;
        }
        return maxCount;
    }
};