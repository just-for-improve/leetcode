class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<char>> result;
        bool havefind = false;
        findSolution(board, result, havefind, 0, 0);
        board = result;
    }
    
    void findSolution(vector<vector<char>>& board, vector<vector<char>> &result, bool& havefind, int i, int j) {
        if (havefind)
            return;
        while (i < board.size() && board[i][j] != '.') {
            i = i + (j + 1) / board.size();
            j = (j + 1) % board.size();
        }
        if (i >= board.size()) {
            result = board;
            havefind=true;
            return;
        }
        bool colchecker[10], rowchecker[10], squarechecker[10];
        memset(colchecker, false, 10);
        memset(rowchecker, false, 10);
        memset(squarechecker, false, 10);
        // row
        for (int k = 0; k < board.size(); ++k) {
            if (board[i][k] != '.')
                rowchecker[board[i][k] - '0'] = true;
        }
        // col
        for (int k = 0; k < board.size(); ++k) {
            if (board[k][j] != '.')
                colchecker[board[k][j] - '0'] = true;
        }
        for (int k = i / 3 * 3; k < i / 3 * 3 + 3; ++k) {
            for (int l = j / 3 * 3; l < j / 3 * 3 + 3; ++l) {
                if (board[k][l] != '.') {
                    squarechecker[board[k][l] - '0'] = true;
                }
            }
        }
        for (int n = 1; n <= 9; ++n) {
            if (rowchecker[n] || colchecker[n] || squarechecker[n])
                continue;
            auto new_board = board;
            new_board[i][j] = (char)('0' + n);
            int new_i = i + (j + 1) / board.size();
            int new_j = (j + 1) % board.size();
            while (i < board.size() && board[i][j] != '.') {
                i = i + (j + 1) / board.size();
                j = (j + 1) % board.size();
            }
            findSolution(new_board, result, havefind, new_i, new_j);
            if (havefind)
                return;
        }
    }
};