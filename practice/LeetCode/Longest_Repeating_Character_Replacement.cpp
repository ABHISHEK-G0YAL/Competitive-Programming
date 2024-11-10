// https://leetcode.com/problems/longest-repeating-character-replacement/

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;
        int l = 0, r = 0, maxTotalF = 0, maxF = 0;
        while (r < s.length()) {
            ++mp[s[r]];
            maxF = max(maxF, mp[s[r]]);
            while (r - l + 1 - maxF > k) {
                --mp[s[l]];
                ++l;
                // // Not required
                // maxF = 0;
                // for (auto &[c, f] : mp) {
                //     maxF = max(maxF, f);
                // }
            }
            maxTotalF = max(maxTotalF, r - l + 1);
            ++r;
        }
        return maxTotalF;
    }
};