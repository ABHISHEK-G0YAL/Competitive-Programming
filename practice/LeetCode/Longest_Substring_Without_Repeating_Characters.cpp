// https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int l = 0, maxLength = 0;
        for (int r = 0; r < s.size(); r++) {
            if (mp.find(s[r]) != mp.end()) {
                l = max(l, mp[s[r]] + 1);
            }
            mp[s[r]] = r;
            maxLength = max(maxLength, r - l + 1);
        }
        return maxLength;
    }
};