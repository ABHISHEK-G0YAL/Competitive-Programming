// https://leetcode.com/problems/continuous-subarray-sum/
// Accepted    36 ms

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        k = abs(k);
        unordered_set<int> prv_md;
        int sum = nums[0];
        prv_md.insert(0);
        if(k != 0)
            prv_md.insert(sum % k);
        for(int i = 1; i < n; i++) {
            if(k == 0) {
                if(nums[i - 1] == 0 and nums[i] == 0)
                    return true;
            }
            else {
                sum += nums[i];
                if(prv_md.find(sum % k) != prv_md.end() and (nums[i] % k != 0 or nums[i - 1] % k == 0))
                    return true;
                else
                    prv_md.insert(sum % k);
            }
        } return false;
    }
};