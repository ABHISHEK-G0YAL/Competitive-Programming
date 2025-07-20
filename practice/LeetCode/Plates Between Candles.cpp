// https://leetcode.com/problems/plates-between-candles/

class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.length();
        vector<int> platesFromLeft(s.length(), -1);

        bool firstCandle = s[0] == '|';
        int platesBetweenCandles = 0;
        for (int i = 1; i < n; i++) {
            platesFromLeft[i] = platesFromLeft[i - 1];
            if (s[i] == '|') {
                if (firstCandle) {
                    platesFromLeft[i] += platesBetweenCandles;
                } else {
                    firstCandle = true;
                    platesFromLeft[i] = 0;
                }
                platesBetweenCandles = 0;
            } else if (s[i] == '*') {
                ++platesBetweenCandles;
            }
        }

        vector<int> ans;
        ans.reserve(queries.size());
        for (auto &q : queries) {
            int left;
            if (s[q[0]] == '*') {
                auto it = upper_bound(
                    platesFromLeft.begin(),
                    platesFromLeft.end(),
                    platesFromLeft[q[0]]);
                left = it != platesFromLeft.end() ? *it : platesFromLeft[q[0]];
            } else {
                left = platesFromLeft[q[0]];
            }
            ans.emplace_back(max(platesFromLeft[q[1]] - left, 0));
        }
        return ans;
    }
};