// https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution2 {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length(), l = 0, r = 0, maxlength = 0, freq[256] = {0};
        while (l < n && r < n) {
            ++freq[s[r]];
            if (freq[s[r]] > 1) {
                while (s[l] != s[r]) {
                    --freq[s[l]];
                    ++l;
                }
                --freq[s[l]];
                ++l;
            }
            maxlength = max(maxlength, r - l + 1);
            ++r;
        }
        return maxlength;
    }
};

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