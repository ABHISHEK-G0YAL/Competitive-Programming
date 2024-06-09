// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int n = prices.size();
        vector<int> future_max(n);
        future_max[n - 1] = prices[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            future_max[i] = max(prices[i], future_max[i + 1]);
        }
        int max_profit = 0;
        for (int i = 0; i < n; i++) {
            max_profit = max(max_profit, future_max[i] - prices[i]);
        }
        return max_profit;
    }
};