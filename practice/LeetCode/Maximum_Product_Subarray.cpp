// https://leetcode.com/problems/maximum-product-subarray/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int l = 0, r = 0, n = nums.size();
        double product = 1, maxProduct = INT_MIN;
        while (r < n) {
            if (nums[r] == 0) {
                while (l < r - 1) {
                    product /= nums[l];
                    maxProduct = max(product, maxProduct);
                    ++l;
                }
                l = r + 1;
            }
            product *= nums[r];
            maxProduct = max(product, maxProduct);
            if (product == 0) {
                product = 1;
            }
            ++r;
        }
        while (l < r - 1) {
            product /= nums[l];
            maxProduct = max(product, maxProduct);
            ++l;
        }
        return maxProduct;
    }
};