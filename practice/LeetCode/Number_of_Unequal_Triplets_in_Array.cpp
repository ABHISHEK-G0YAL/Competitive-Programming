// https://leetcode.com/problems/number-of-unequal-triplets-in-array/

class Solution {
public:
    // O(N ^ 3) | 7 ms Beats 60.28%
    int unequalTripletsCubicBruteForce(vector<int>& nums) {
        int n = nums.size(), count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (nums[i] != nums[j] && nums[j] != nums[k] && nums[k] != nums[i]) {
                        ++count;
                    } 
                }
            }
        }
        return count;
    }

    // O(N ^ 2) | 0 ms Beats 100.00%
    int unequalTripletsQuadratic(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int i : nums) {
            ++mp[i];
        }
        int n = nums.size(), count = 0;
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            for (auto jt = next(it); jt != mp.end(); ++jt) {
                count +=  it->second * jt->second * max(n - it->second - jt->second, 0);
            }
            n = n - it->second;
        }
        return count / 2;
    }

    // O(N) | 0 ms Beats 100.00%
    int unequalTripletsLinear(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int i : nums) {
            ++mp[i];
        }
        int left = 0, n = nums.size(), count = 0, right;
        for (auto &[i, f] : mp) {
            right = n - left - f;
            count += left * f * right;
            left += f;
        }
        return count;
    }

    int unequalTriplets(vector<int>& nums) {
        // return unequalTripletsCubicBruteForce(nums);
        // return unequalTripletsQuadratic(nums);
        return unequalTripletsLinear(nums);
    }
};