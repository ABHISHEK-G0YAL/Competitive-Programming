// https://leetcode.com/problems/out-of-boundary-paths/

class def_long {
    public:
    long value = -1;
};
class SolutionOld {
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

#define MOD 1000000007

class Solution {
public:
    map<tuple<int, int, int>, int> mem;
    int findPaths(int &m, int &n, int maxMove, int startRow, int startColumn) {
        tuple<int, int, int> key = make_tuple(maxMove, startRow, startColumn);
        auto it = mem.find(key);
        if (it != mem.end()) {
            return it->second;
        }
        if (startRow < 0 || startColumn < 0
        || startRow == m || startColumn == n) {
            return 1;
        }
        if (maxMove == 0) {
            return 0;
        }
        int paths = (
            (long) findPaths(m, n, maxMove - 1, startRow + 1, startColumn)
             + findPaths(m, n, maxMove - 1, startRow, startColumn + 1)
             + findPaths(m, n, maxMove - 1, startRow - 1, startColumn)
             + findPaths(m, n, maxMove - 1, startRow, startColumn - 1)
        ) % MOD;
        mem.insert({ key, paths });
        return paths;
    }
};