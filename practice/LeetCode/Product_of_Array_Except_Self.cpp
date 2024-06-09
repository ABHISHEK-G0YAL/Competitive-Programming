// https://leetcode.com/problems/product-of-array-except-self/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long allProduct = 1;
        int zeroCount = 0;
        for (int &num : nums) {
            if (num != 0) {
                allProduct *= num;
            } else {
                ++zeroCount;
            }
        }
        vector<int> solution;
        if (zeroCount == 0) {
            for (int &num : nums) {
                solution.push_back(allProduct / num);
            }
        } else if (zeroCount == 1) {
            for (int &num : nums) {
                if (num == 0) {
                    solution.push_back(allProduct);
                } else {
                    solution.push_back(0);
                }
            }
        } else {
            for (int &num : nums) {
                solution.push_back(0);
            }
        }
        return solution;
    }
};