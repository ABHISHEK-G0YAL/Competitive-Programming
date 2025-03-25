// https://leetcode.com/problems/neither-minimum-nor-maximum/

class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        int minimum = *min_element(nums.begin(), nums.end());
        int maximum = *max_element(nums.begin(), nums.end());
        for (int i : nums) {
            if (i != minimum && i != maximum) {
                return i;
            }
        }
        return -1;
    }
};