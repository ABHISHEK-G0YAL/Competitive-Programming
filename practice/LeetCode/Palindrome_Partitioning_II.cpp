// https://leetcode.com/problems/palindrome-partitioning-ii/

class Solution {
    class default_int {
    public:
        int data = -1;
    };
    unordered_map<int, unordered_map<int, default_int> > dp, pdp;
    int ispalindrome(string &s, int i, int j) {
        if(pdp[i][j].data != -1)
            return pdp[i][j].data;
        while(i < j) {
            if(s[i] != s[j])
                return pdp[i][j].data = 0;
            ++i;
            --j;
        }
        return pdp[i][j].data = 1;
    }
    int solve(string &s, int i, int j) {
        if(dp[i][j].data != -1)
            return dp[i][j].data;
        if(ispalindrome(s, i, j))
            return 0;
        int ans = (j - i) + 1;
        for(int k = i; k <= j - 1; k++)
            if(ispalindrome(s, i, k))
                ans = min(ans, 1 + solve(s, k + 1, j));
        return dp[i][j].data = ans;
    }
public:
    int minCut(string s) {
        return solve(s, 0, s.size() - 1);
    }
};