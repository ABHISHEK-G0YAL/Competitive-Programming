// https://leetcode.com/problems/minimum-window-substring/

class Solution {
public:
    bool includesEveryCh(unordered_map<char, int> &sm, unordered_map<char, int> &tm) {
        for (auto &[c, f] : tm) {
            if (sm[c] < f) {
                return false;
            }
        }
        return true;
    }

    // 147 ms Beats 6.91%
    string minWindow2(string s, string t) {
        unordered_map<char, int> sm;
        unordered_map<char, int> tm;
        for (char c : t) {
            ++tm[c];
        }
        int minLength = INT_MAX, l = 0, r = -1, n = s.length(), ansStart;
        // string minSubStr;
        while (r < n) {
            if (includesEveryCh(sm, tm)) {
                if (r - l + 1 < minLength) {
                    minLength = r - l + 1;
                    ansStart = l;
                    // minSubStr = s.substr(l, minLength);
                }
                --sm[s[l]];
                ++l;
            } else {
                ++r;
                ++sm[s[r]];
            }
        }
        return minLength < INT_MAX ? s.substr(ansStart, minLength) : "";
    }

    // 15 ms Beats 68.97%
    string minWindow(string s, string t) {
        unordered_map<char, int> tm;
        for (char c : t) {
            ++tm[c];
        }
        int minLength = INT_MAX, l = 0, r = -1, n = s.length(), ansStart, required = t.length();
        // string minSubStr;
        while (r < n) {
            if (required == 0) {
                if (r - l + 1 < minLength) {
                    minLength = r - l + 1;
                    ansStart = l;
                    // minSubStr = s.substr(l, minLength);
                }
                if (tm.find(s[l]) != tm.end()) {
                    ++tm[s[l]];
                    if (tm[s[l]] > 0) {
                        ++required;
                    }
                }
                ++l;
            } else {
                ++r;
                if (tm.find(s[r]) != tm.end()) {
                    if (tm[s[r]] > 0) {
                        --required;
                    }
                    --tm[s[r]];
                }
            }
        }
        return minLength < INT_MAX ? s.substr(ansStart, minLength) : "";
    }
};