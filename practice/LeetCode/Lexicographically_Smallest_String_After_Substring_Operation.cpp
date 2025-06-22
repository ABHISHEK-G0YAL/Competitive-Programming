// https://leetcode.com/problems/lexicographically-smallest-string-after-substring-operation/

class Solution {
public:
    string smallestString(string s) {
        bool edited = false;
        for (char &c : s) {
            if (c == 'a' && !edited) {
                continue;
            }
            if (c == 'a') {
                break;
            }
            c -= 1;
            edited = true;
        }
        if (!edited) {
            s[s.length() - 1] = 'z';
        }
        return s;
    }
};