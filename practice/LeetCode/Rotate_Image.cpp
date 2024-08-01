// https://leetcode.com/problems/rotate-image/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size() - 1;
        for (int S = 0; S < matrix.size() / 2; ++S) {
            int i = S, E = n - S, in, jn;
            for (int j = S; j < E; ++j) {
                cout << i << ", " << j << " | ";
                in = S + E - j; jn = S;
                swap(matrix[i][j], matrix[in][jn]);
                i = S + E - j; j = S;

                cout << i << ", " << j << " | ";
                jn = i; in = E;
                swap(matrix[i][j], matrix[in][jn]);
                j = i; i = E;

                cout << i << ", " << j << " | ";
                in = S + E - j; jn = E;
                swap(matrix[i][j], matrix[in][jn]);
                i = S + E - j; j = E;

                cout << i << ", " << j << " | ";
                jn = i; in = S;
                // swap(matrix[i][j], matrix[in][jn]);
                j = i; i = S;

                cout << endl;
            }
        }
    }
};