// https://leetcode.com/problems/product-of-array-except-self/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n, 1), suffix(n, 1), ans(n);
        for (int i = 0; i < n - 1; i++) {
            prefix[i + 1] = nums[i] * prefix[i];
        }
        for (int i = n - 1; i > 0; i--) {
            suffix[i - 1] = nums[i] * suffix[i];
        }
        for (int i = 0; i < n; i++) {
            ans[i] = prefix[i] * suffix[i];
        }
        return ans;
    }
};