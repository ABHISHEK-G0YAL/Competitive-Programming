// https://leetcode.com/problems/sum-of-two-integers/

class Solution {
public:
    int getSum(int a, int b) {
        int carry = (a & b) << 1, sum = a ^ b;
        if (carry) {
            return getSum(sum, carry);
        }
        return sum;
    }
};
