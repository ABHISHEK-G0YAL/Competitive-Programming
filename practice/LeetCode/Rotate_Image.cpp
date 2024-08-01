// https://leetcode.com/problems/rotate-image/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size() - 1;
        for (int S = 0; S < matrix.size() / 2; ++S) {
            int i = S, E = n - S, io, jo;
            for (int j = S; j < E; ++j) {
                io = i; jo = j;
                i = S + E - j; j = S;
                swap(matrix[io][jo], matrix[i][j]);

                io = i; jo = j;
                j = i; i = E;
                swap(matrix[io][jo], matrix[i][j]);

                io = i; jo = j;
                i = S + E - j; j = E;
                swap(matrix[io][jo], matrix[i][j]);

                j = i; i = S;
                cout << endl;
            }
        }
    }
};