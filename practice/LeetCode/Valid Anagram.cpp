// https://leetcode.com/problems/valid-anagram/

class Solution {
public:
    // TC - O(N log N)
    bool isAnagram1(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }

    // TC - O(N)
    bool isAnagram(string s, string t) {
        unordered_map<char, int> sm;
        unordered_map<char, int> tm;
        for (char c : s) {
            ++sm[c];
        }
        for (char c : t) {
            ++tm[c];
        }
        return sm == tm;
    }
};