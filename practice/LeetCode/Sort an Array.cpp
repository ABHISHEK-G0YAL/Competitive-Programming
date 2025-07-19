// https://leetcode.com/problems/sort-an-array/

class Solution {
public:
    int MIN_NUM = -50005;
    int MAX_NUM = 50005;
    vector<int> sortArray(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int &num : nums) {
            ++mp[num];
        }
        vector<int> ans;
        ans.reserve(nums.size());
        for (int i = MIN_NUM; i <= MAX_NUM; ++i) {
            if (mp.count(i)) {
                ans.insert(ans.end(), mp[i], i); // append mp[i] copies of i
            }
        }
        return ans;
    }
};