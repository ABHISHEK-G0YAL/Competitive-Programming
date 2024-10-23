// https://leetcode.com/problems/spiral-matrix//

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) {
            return {};
        }
        int left = 0;
        int right = matrix[0].size() - 1;
        int top = 0;
        int bottom = matrix.size() - 1;
        vector<int> spiralOrder;
        while (top <= bottom && left <= right) {
            for(int i = left; i <= right; i++) {
                spiralOrder.push_back(matrix[top][i]);
            }
            ++top;
            for(int i = top; i <= bottom; i++) {
                spiralOrder.push_back(matrix[i][right]);
            }
            --right;
            if (top <= bottom && left <= right) {
                for(int i = right; i >= left; i--) {
                    spiralOrder.push_back(matrix[bottom][i]);
                }
                --bottom;
                for(int i = bottom; i >= top; i--) {
                    spiralOrder.push_back(matrix[i][left]);
                }
                ++left;
            }
        }
        return spiralOrder;
    }
};