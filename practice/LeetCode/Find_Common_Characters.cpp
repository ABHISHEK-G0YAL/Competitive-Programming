// https://leetcode.com/problems/find-common-characters/
// Accepted    12 ms

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<string> ans;
        int a[26] = {};
        for(auto i : A[0])
            a[i - 'a']++;
        for(auto s : A) {
            int t[26] = {};
            for(auto i : s)
                t[i - 'a']++;
            for(int i = 0; i < 26; i++)
                a[i] = min(a[i], t[i]);
        }
        for(int i = 0; i < 26; i++) {
            string ch = "";
            ch = ch + char('a' + i);
            while(a[i]--) {
                ans.push_back(ch);
            }
        } return ans;
    }
};