// https://leetcode.com/problems/missing-number/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for (int i : nums) {
            sum += i;
        }
        return ((n * (n + 1)) / 2) - sum;
    }
};
