// https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, vector<int> > freq;
        for(int i = 0; i < n; i++)
            freq[nums[i]].push_back(i);
        for(int i = 0; i < n; i++) {
            int to_find = target - nums[i];
            if(to_find != nums[i] and !freq[to_find].empty())
                return {i, freq[to_find][0]};
            if(to_find == nums[i] and freq[to_find].size() > 1)
                return {i, freq[to_find][1]};
        } return {};
    }
};