// https://leetcode.com/problems/maximum-product-subarray/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        double maxp = INT_MIN, p = 1, fnp = 1, flag = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) {
                maxp = max(maxp, (double)0);
                if(flag)
                    maxp = max(maxp, p / fnp);
                p = 1;
                fnp = 1;
                flag = 0;
            }
            else {
                p *= nums[i];
                if(fnp > 0)
                    fnp *= nums[i];
                else
                    flag = 1;
                maxp = max(maxp, p);
            }
        }
        if(flag)
            maxp = max(maxp, p / fnp);
        return maxp;
    }
};