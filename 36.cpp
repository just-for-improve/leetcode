class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool records[10];
        // rule1
        for (int i = 0; i < 9; ++i) {
            init(records);
            for (int j = 0; j < 9; ++j) {
               if (board[i][j] != '.') {
                   int value = board[i][j] - '0';
                   if (records[value]) return false;
                   records[value] = true;
               }
            }
        }
        // rule2
         for (int i = 0; i < 9; ++i) {
            init(records);
            for (int j = 0; j < 9; ++j) {
               if (board[j][i] != '.') {
                   int value = board[j][i] - '0';
                   if (records[value]) return false;
                   records[value] = true;
               }
            }
        }
        // rule3
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                init(records);
                for (int l = i; l < i + 3; ++l) {
                    for (int m = j; m < j + 3; ++m) {
                        if (board[l][m] != '.') {
                            int value = board[l][m] - '0';
                            if (records[value]) return false;
                            records[value] = true;
                         }
                    }
                }
            }
        }
        return true;
    }
    void init(bool records[10]) {
        for (int i = 0; i < 10; ++i) {
            records[i] = false;
        }
    }
};