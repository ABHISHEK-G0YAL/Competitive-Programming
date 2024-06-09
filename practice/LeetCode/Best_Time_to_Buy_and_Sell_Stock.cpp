// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int n = prices.size();
        int future_max = 0, max_profit = 0;
        for (int i = n - 1; i >= 0; i--) {
            future_max = max(prices[i], future_max);
            max_profit = max(max_profit, future_max - prices[i]);
        }
        return max_profit;
    }
};