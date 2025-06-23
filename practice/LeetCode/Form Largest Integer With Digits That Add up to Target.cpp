// https://leetcode.com/problems/form-largest-integer-with-digits-that-add-up-to-target/

class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
        string temp;
        vector<string> dp(target + 1);
        for(int i = 1; i <= target; ++i) {
            // dp[i] = dp[i - 1];
            for(int j = 0; j < 9; j++) {
                if(cost[j] > i)
                    continue;
                if(dp[i - cost[j]].empty() and i - cost[j] != 0) // to use exact target cost, remove if largest number is to be made using <= target
                    continue;
                temp = dp[i - cost[j]] + char('1' + j);
                if(temp.size() == dp[i].size() ? temp > dp[i] : temp.size() > dp[i].size())
                    dp[i] = temp;
            }
        }
        return dp[target].empty() ? "0" : dp[target];
    }
};