// https://leetcode.com/problems/valid-palindrome/
// Accepted    8 ms

class Solution {
public:
    inline bool isAlphaNumeric(char &c) {
        return (c >= 'a' and c <= 'z') or (c >= 'A' and c <= 'Z') or (c >= '0' and c <= '9');
    }
    inline void toLower(char &c) {
        if(c >= 'A' and c <= 'Z')
            c = c + 32;
    }
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while(i < j) {
            if(!isAlphaNumeric(s[i]))
                i += 1;
            else if(!isAlphaNumeric(s[j]))
                j -= 1;
            else {
                toLower(s[i]);
                toLower(s[j]);
                if(s[i] != s[j])
                    return false;
                i += 1;
                j -= 1;
            }
        }
        return true;
    }
};