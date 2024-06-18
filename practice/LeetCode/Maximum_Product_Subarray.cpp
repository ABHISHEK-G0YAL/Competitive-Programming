// https://leetcode.com/problems/maximum-product-subarray/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        const int n = nums.size();
        double product1 = 1, product2 = 1, maxProduct = INT_MIN;
        for(int i = 0; i < n; i++) {
            product1 *= nums[i];
            product2 *= nums[n - 1 - i];
            maxProduct = max({product1, product2, maxProduct});
            if (product1 == 0) {
                product1 = 1;
            }
            if (product2 == 0) {
                product2 = 1;
            }
        }
        return maxProduct;
    }
};