// https://leetcode.com/problems/missing-number/

class Solution {
public:
    int missingNumberUsingXor(vector<int>& nums) {
        int xor1 = 0, xor2 = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            xor1 ^= nums[i];
            xor2 ^= i + 1;
        }
        return xor1 ^ xor2;
    }

    int missingNumberUsingSum(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for (int i : nums) {
            sum += i;
        }
        return ((n * (n + 1)) / 2) - sum;
    }

    int missingNumber(vector<int>& nums) {
        return missingNumberUsingXor(nums);
    }
};
