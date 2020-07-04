// https://leetcode.com/problems/arranging-coins/
// Accepted    12 ms

class Solution {
public:
    int arrangeCoins(int n) {
        int c = 1;
        while(c <= n) {
            n -= c;
            ++c;
        }
        return c - 1;
    }
};