// https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indice_map;
        for (int i = 0; i < nums.size(); i++) {
            // candidate index
            int c_i = indice_map[target - nums[i]];
            if (c_i) {
                return {c_i - 1, i};
            }
            indice_map[nums[i]] = i + 1;
        }
        return {};
    }
};