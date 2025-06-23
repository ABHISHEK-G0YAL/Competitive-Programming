// https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/

class Solution {
public:
    int countKDifferenceBruteForce(vector<int>& nums, int k) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (abs(nums[i] - nums[j]) == k) {
                    ++count;
                }
            }
        }
        return count;
    }

    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int i : nums) {
            ++mp[i];
        }
        int count = 0;
        auto get = [&](int i) {
            return mp.find(i) != mp.end() ? mp[i] : 0;
        };
        for (auto &[i, f] : mp) {
            count += f * get(i + k) ;
            count += f * get(i - k);
            f = 0;
        }
        return count;
    }
};