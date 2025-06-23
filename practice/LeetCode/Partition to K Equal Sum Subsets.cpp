// https://leetcode.com/problems/partition-to-k-equal-sum-subsets/

class Solution {
public:
    bool canMakeKSubsetsOfSum(vector<int> &nums, vector<int> &subsets, int i = 0) {
        if(i == nums.size()) {
            for(int i : subsets)
                if(i != 0)
                    return false;
            return true;
        }
        for(int &subset : subsets) {
            if(subset >= nums[i]) {
                subset -= nums[i];
                if(canMakeKSubsetsOfSum(nums, subsets, i + 1))
                    return true;
                subset += nums[i];
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for(int i : nums)
            sum += i;
        if(sum % k)
            return false;
        else {
            vector<int> subsets(k, sum / k);
            sort(nums.rbegin(), nums.rend());
            return canMakeKSubsetsOfSum(nums, subsets);
        }
    }
};