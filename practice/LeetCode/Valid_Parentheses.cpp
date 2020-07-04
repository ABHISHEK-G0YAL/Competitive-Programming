// https://leetcode.com/problems/valid-parentheses/
// Accepted    0 ms

class Solution {
public:
    unordered_map<char, char> mp = {
        {')', '('},
        {'}', '{'},
        {']', '['}
    };
    bool isValid(string s) {
        stack<char> st;
        for(char &c : s) {
            if(c == '(' or c == '[' or c == '{')
                st.push(c);
            else if(!st.empty() and st.top() == mp[c])
                st.pop();
            else
                return false;
        }
        return st.empty() ? true : false;
    }
};