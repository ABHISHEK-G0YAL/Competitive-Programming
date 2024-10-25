// https://leetcode.com/problems/edit-distance/

class SolutionOld {
public:
    vector<vector<int> > mem=vector<vector<int> > (1000,vector<int> (1000,-1));
    int minDistance(string w1, string w2) {
        int l1=w1.length(),l2=w2.length();
        if(mem[l1][l2]!=-1)
            return mem[l1][l2];
        if(l1==0 || l2==0)
            mem[l1][l2]=l1?l1:l2;
        else if(w1[0]==w2[0])
            mem[l1][l2]=minDistance(w1.substr(1),w2.substr(1));
        else
            mem[l1][l2]=1+min( { minDistance(w1.substr(1),w2.substr(1)),
                          minDistance(w1.substr(1),w2),
                         minDistance(w1,w2.substr(1)) } );
        return mem[l1][l2];
    }
};

class Solution {
public:
    // replacing recursive (i + 1, j + 1) -> dp[i - 1] [j - 1]
    // inserting recursive (i, j + 1)-> dp[i] [j - 1]
    // deleting recursive (i + 1, j) -> dp[i - 1] [j]
    int editDistance(string &word1, string &word2) {
        int n = word1.length(), m = word2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));

        for (int i = 0; i <= n; i++) {
            dp[i][0] = i;
        }

        for (int j = 0; j <= m; j++) {
            dp[0][j] = j;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + min({ dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j] });
                }
            }
        }
        return dp[n][m];
    }
    int minDistance(string word1, string word2) {
        return editDistance(word1, word2);
    }
};
