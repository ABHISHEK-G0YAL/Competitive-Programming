// https://leetcode.com/problems/word-search/

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word, int i = 0, int j = 0, bool start = true) {
        int n = board.size(), m = board[0].size();
        if (word.length() == 0)
            return true;
        if (j < 0 || i < 0 || i >= n || j >= m) {
            return false;
        }
        bool ans = false;
        if (start) {
            for (int i = 0 ; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (board[i][j] == word[0]) {
                        char c = board[i][j];
                        board[i][j] = '*';
                        ans = ans || exist(board, word.substr(1), i + 1, j, false);
                        ans = ans || exist(board, word.substr(1), i - 1, j, false);
                        ans = ans || exist(board, word.substr(1), i, j + 1, false);
                        ans = ans || exist(board, word.substr(1), i, j - 1, false);
                        board[i][j] = c;
                    }
                }
            }
            return ans;
        }
        if (board[i][j] == word[0]) {
            char c = board[i][j];
            board[i][j] = '*';
            ans = ans || exist(board, word.substr(1), i + 1, j, false);
            ans = ans || exist(board, word.substr(1), i - 1, j, false);
            ans = ans || exist(board, word.substr(1), i, j + 1, false);
            ans = ans || exist(board, word.substr(1), i, j - 1, false);
            board[i][j] = c;
        }
        return ans;
    }
};