// https://leetcode.com/problems/assign-cookies/

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.rbegin(), g.rend());
        sort(s.rbegin(), s.rend());
        int gi = 0, si = 0;
        while (si < s.size()) {
            while (gi < g.size() && s[si] < g[gi]) {
                ++gi;
            }
            if (gi == g.size()) {
                break;
            }
            ++gi;
            ++si;
        }
        return si;
    }
};