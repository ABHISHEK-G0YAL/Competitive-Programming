// https://leetcode.com/problems/permutation-in-string/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) {
            return false;
        }
        unordered_map<char, int> mp1, mp2;
        for (char c : s1) {
            ++mp1[c];
        }
        int l = 0, r = 0;
        while (r < s1.length()) {
            ++mp2[s2[r]];
            ++r;
        }
        if (mp1 == mp2) {
            return true;
        }
        while (r < s2.length()) {
            ++mp2[s2[r]];
            --mp2[s2[l]];
            if (mp2[s2[l]] == 0) {
                mp2.erase(s2[l]);
            }
            if (mp1 == mp2) {
                return true;
            }
            ++r;
            ++l;
        }
        return false;
    }
};