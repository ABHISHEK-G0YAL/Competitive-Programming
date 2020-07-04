// https://leetcode.com/problems/stone-game-ii/
// Accepted    12 ms

class Solution {
    vector<vector<vector<int> > > mem = vector<vector<vector<int> > >(2, vector<vector<int>>(105, vector<int>(105, -1)));
public:
    int stoneGameII(vector<int>& piles, int m = 1, bool turn = true, int i = 0) {
        if(i >= piles.size())
            return 0;
        if(mem[turn][i][m] != -1)
            return mem[turn][i][m];
        if(turn) {
            int sum = 0, maxSum = 0;
            for(int x = 0; x < 2 * m; x++) {
                if(i + x >= piles.size())
                    break;
                sum += piles[i + x];
                maxSum = max(maxSum, sum + stoneGameII(piles, max(x + 1, m), !turn, i + x + 1));
            }
            return mem[turn][i][m] = maxSum;
        }
        else {
            int sum = 0, minSum = INT_MAX;
            for(int x = 0; x < 2 * m; x++)
                minSum = min(minSum, stoneGameII(piles, max(x + 1, m), !turn, i + x + 1));
            return mem[turn][i][m] = minSum;
        }
    }
};