// https://leetcode.com/problems/set-matrix-zeroes/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        unordered_set<int> rows, cols;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }
        for (const int &r : rows) {
            for (int j = 0; j < m; j++) {
                matrix[r][j] = 0;
            }
        }
        for (const int &c : cols) {
            for (int i = 0; i < n; i++) {
                matrix[i][c] = 0;
            }
        }
    }
};