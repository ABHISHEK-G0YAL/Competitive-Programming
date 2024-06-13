// https://leetcode.com/problems/maximum-product-subarray/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        const int n = nums.size();
        double product = 1, maxProduct = INT_MIN;
        for(int i = 0; i < n; i++) {
            product *= nums[i];
            maxProduct = max(product, maxProduct);
            if (product == 0) {
                product = 1;
            }
        }
        product = 1;
        for(int i = n - 1; i >= 0; i--) {
            product *= nums[i];
            maxProduct = max(product, maxProduct);
            if (product == 0) {
                product = 1;
            }
        }
        return maxProduct;
    }
};