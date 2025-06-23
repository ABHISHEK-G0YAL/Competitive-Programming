// https://leetcode.com/problems/word-search/

class Solution {
public:
    vector<vector<char>> board;
    bool searchFrom(string word, int i, int j) {
        int n = board.size(), m = board[0].size();
        if (word.length() == 0)
            return true;
        if (j < 0 || i < 0 || i >= n || j >= m) {
            return false;
        }
        bool ans = false;
        if (board[i][j] == word[0]) {
            char c = board[i][j];
            board[i][j] = '*';
            ans = ans || searchFrom(word.substr(1), i + 1, j);
            ans = ans || searchFrom(word.substr(1), i - 1, j);
            ans = ans || searchFrom(word.substr(1), i, j + 1);
            ans = ans || searchFrom(word.substr(1), i, j - 1);
            board[i][j] = c;
        }
        return ans;
    }

    bool exist(vector<vector<char>>& board, string word) {
        this->board = board;
        int n = board.size(), m = board[0].size();
        for (int i = 0 ; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (searchFrom(word, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
};