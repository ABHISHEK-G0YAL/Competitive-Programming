// https://leetcode.com/problems/3sum/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> mp;
        for (int &a : nums) {
            ++mp[a];
        }
        int n = nums.size();
        set<vector<int> > ans;
        for (int i = 0; i < n; i++) {
            if (i != 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            --mp[nums[i]];
            for (int j = i + 1; j < n; j++) {
                --mp[nums[j]];
                int to_search = -(nums[i] + nums[j]);
                // cout << i << ": " << nums[i] << ", ";
                // cout << j << ": " << nums[j] << ", ";
                // cout << to_search << " " << mp[to_search]  << endl;
                if (to_search >= nums[j] && mp[to_search] > 0) {
                    ans.insert({nums[i], nums[j], to_search});
                }
            }
            for (int j = i + 1; j < n; j++) {
                ++mp[nums[j]];
            }
        }
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};