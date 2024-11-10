// https://leetcode.com/problems/valid-parentheses/

class Solution {
public:
    bool isValid(string s) {
        string openingBrackets = "{[(";
        unordered_map<char, char> mp = {
            {']', '['},
            {'}', '{'},
            {')', '('}
        };
        stack<char> st;
        for (char c : s) {
            if (openingBrackets.find(c) != string::npos) {
                st.push(c);
            } else {
                if (!st.empty() && st.top() == mp[c]) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        return st.empty();
    }
};