// https://leetcode.com/problems/out-of-boundary-paths/
// Accepted    136 ms

class def_long {
    public:
    long value = -1;
};
class Solution {
    int m, n;
    unordered_map<int, unordered_map<int, unordered_map<int, def_long> > > mem;
    long solve(int i, int j, int N) {
        if(mem[i][j][N].value != -1)
            return mem[i][j][N].value;
        if(N < 0)
            return 0;
        if(i >= m or j >= n or i < 0 or j < 0)
            return 1;
        return mem[i][j][N].value =
            (solve(i + 1, j, N - 1) +
            solve(i - 1, j, N - 1) +
            solve(i, j + 1, N - 1) +
            solve(i, j - 1, N - 1))
            % 1000000007;
    }
public:
    int findPaths(int m, int n, int N, int i, int j) {
        this->m = m, this->n = n;
        return solve(i, j, N);
    }
};