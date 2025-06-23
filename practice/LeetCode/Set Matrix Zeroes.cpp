// https://leetcode.com/problems/set-matrix-zeroes/

class Solution {
public:
    // ~O(n + m) space    
    void setZeroesONM(vector<vector<int>>& matrix) {
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

    // ~O(1) space  
    void setZeroesO1(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        bool firstRowZero = false;

        // Check if the first row has any zeroes
        for (int j = 0; j < m; ++j) {
            if (matrix[0][j] == 0) {
                firstRowZero = true;
                break;
            }
        }

        // Use the first row and first column to mark zeroes
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0; // Mark the corresponding first column
                    matrix[0][j] = 0; // Mark the corresponding first row
                }
            }
        }

        // Set matrix elements to zero based on markers in the first row and column
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Handle the first column separately
        if (matrix[0][0] == 0) {
            for (int i = 1; i < n; ++i) {
                matrix[i][0] = 0;
            }
        }

        // Handle the first row separately if needed
        if (firstRowZero) {
            for (int j = 0; j < m; ++j) {
                matrix[0][j] = 0;
            }
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {
        setZeroesO1(matrix);
    }
};