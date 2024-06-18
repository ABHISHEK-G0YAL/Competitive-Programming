// https://leetcode.com/problems/3sum/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        set<vector<int> > ans;
        for (int i = 0; i < n; i++) {
            if (i != 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int target = -nums[i];
            unordered_map<int, int> indice_map;
            for (int j = i + 1; j < n; j++) {
                int c_i = indice_map[target - nums[j]];
                if (c_i) {
                    ans.insert({nums[i], nums[c_i - 1], nums[j]});
                }
                indice_map[nums[j]] = j + 1;
            }
        }
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};