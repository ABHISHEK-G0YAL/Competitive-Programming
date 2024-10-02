// https://leetcode.com/problems/maximum-product-subarray/
// https://www.youtube.com/watch?v=lXVy6YWFcRM

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        const int n = nums.size();
        double currMax = 1, currMin = 1, maxProduct = INT_MIN, newMax;
        for(int i = 0; i < n; i++) {
            newMax = max({currMax * nums[i], currMin * nums[i], double(nums[i])});
            currMin = min({currMax * nums[i], currMin * nums[i], double(nums[i])});
            currMax = newMax;
            maxProduct = max(currMax, maxProduct);
        }
        return maxProduct;
    }
};