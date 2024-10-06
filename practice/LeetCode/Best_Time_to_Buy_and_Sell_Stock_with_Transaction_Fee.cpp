// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

class Solution {
public:
    // TLE - 19 / 44 testcases passed
    int maxProfitRecursion(vector<int>& prices, int fee, int i = 0, int j = -1) {
        if(i == prices.size()) {
            return 0;
        }
        if (j == -1) { // buy
            return max(
                maxProfitRecursion(prices, fee, i + 1, i),
                maxProfitRecursion(prices, fee, i + 1, j)
            );
        } else { // sell
            return max(
                ((prices[i] - prices[j]) - fee) + maxProfitRecursion(prices, fee, i + 1, -1),
                maxProfitRecursion(prices, fee, i + 1, j)
            );
        }
    }

    // TLE - 34 / 44 testcases passed
    unordered_map <int, unordered_map<int, int> > memo;
    int maxProfitMemo(vector<int>& prices, int fee, int i = 0, int j = -1) {
        if (memo[i].find(j) != memo[i].end()) {
            return memo[i][j];
        }
        if(i == prices.size()) {
            return 0;
        }
        if (j == -1) { // buy
            return memo[i][j] = max(
                maxProfitMemo(prices, fee, i + 1, i),
                maxProfitMemo(prices, fee, i + 1, j)
            );
        } else { // sell
            return memo[i][j] = max(
                ((prices[i] - prices[j]) - fee) + maxProfitMemo(prices, fee, i + 1, -1),
                maxProfitMemo(prices, fee, i + 1, j)
            );
        }
    }

    // TLE - 34 / 44 testcases passed
    int maxProfitDP(vector<int>& prices, int fee) {
        int n = prices.size();
        // same result on replacing this with vector and shifting j 
        unordered_map<int, unordered_map<int, int> > dp; 
        for (int i = n - 1; i >= 0; i--) {
            for (int j = -1; j < i; j++) {
                if (j == -1) { // buy
                    dp[i][-1] = max(dp[i + 1][i], dp[i + 1][-1]);
                } else { // sell
                    dp[i][j] = max(((prices[i] - prices[j]) - fee) + dp[i + 1][-1], dp[i + 1][j]);
                }
            }
        }
        return dp[0][-1];
    }

    // AC - 73ms Beats 81.54%
    int maxProfitGreedyDP(vector<int>& prices, int fee) {
        int n = prices.size();
        int buy = -prices[0], sell = 0;
        for (int price : prices) {
            // max realized gain if holding until now
            buy = max(buy, sell - price);
            // max realized gain if sold until now
            sell = max(sell, buy + price - fee);
        }
        return sell;
    }

    int maxProfit(vector<int>& prices, int fee) {
        // return maxProfitRecursion(prices, fee);
        // return maxProfitMemo(prices, fee);
        // return maxProfitDP(prices, fee);
        return maxProfitGreedyDP(prices, fee);
    }
};