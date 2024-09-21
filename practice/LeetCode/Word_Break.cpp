// https://leetcode.com/problems/word-break/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordDictLookup(wordDict.begin(), wordDict.end());
        int n = s.length();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 0; i < n; i++) {
            for(int j = 0; j <= i; j++) {
                if (dp[j] && wordDictLookup.contains(s.substr(j, i - j + 1))) {
                    dp[i + 1] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};