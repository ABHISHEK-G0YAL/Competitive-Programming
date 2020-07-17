// https://leetcode.com/problems/reverse-words-in-a-string/

class Solution {
public:
    string reverseWords(string s) {
        stack<string> words;
        int n = s.length();
        int start = 0;
        for(int i = 0; i <= n; i++) {
            if(i == n or s[i] == ' ') {
                words.push(s.substr(start, i - start));
                start = i + 1;
            }
        }
        s = "";
        while(!words.empty()) {
            string word = words.top();
            words.pop();
            if(word == "")
                continue;
            s += word;
            s += " ";
        }
        if(!s.empty())
            s.pop_back();
        return s;
    }
};