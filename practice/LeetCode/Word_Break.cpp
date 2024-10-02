// https://leetcode.com/problems/word-break/

class Solution {
public:
    // Time complexity O(N^3) due to substr
    bool wordBreak1(string &s, vector<string>& wordDict) {
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

    // Time complexity O(N^2)
    bool wordBreak2(string &s, vector<string>& wordDict) {
        unordered_set<string> wordDictLookup(wordDict.begin(), wordDict.end());
        int n = s.length();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 0; i <= n; i++) {
            if(dp[i]) {
                string word;
                for(int j = i; j < s.length(); j++) {
                    word += s[j];
                    if (wordDictLookup.contains(word)) {
                        dp[j + 1] = true;
                    }
                }
            }
        }
        return dp[n];
    }

    bool wordBreak(string &s, vector<string>& wordDict) {
        return wordBreak2(s, wordDict);
    }
};