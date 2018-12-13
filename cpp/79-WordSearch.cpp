// https://leetcode-cn.com/problems/word-search/description/
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        if (board.size() == 0 || board[0].size() == 0) return false;
        
        int m = board.size();
        int n = board[0].size();
        vector<int> back;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (word[0] == board[i][j]) {
                    back.clear();
                    bool find = have(board, word, i, j, 1, back);
                    if (find) return true;
                }
            }
        }
        return false;
    }
    
    bool have(vector<vector<char>>& board, string word, int i, int j, int index, vector<int> back) {
        if (word.size() <= index) return true;
        back.push_back(i);
        back.push_back(j);
        vector<int> p {i, j-1, i, j+1, i-1, j, i+1, j};
        for (int k = 0; k < 4; ++k) {
            if (valid(p[2*k], p[2*k+1], board, back) && 
                board[p[2*k]][p[2*k+1]] == word[index] && 
                have(board, word, p[2*k], p[2*k+1], index+1, back)) return true;
        }
        return false;
    }
    
    bool valid(int i, int j, vector<vector<char>>& board, const vector<int>& back) {
        auto r1 = (i < 0 || i >= board.size() || j < 0 || j >= board[0].size());
        bool r2 = true;
        for (int k = 0; k < back.size();) {
            if (back[k] == i && back[k+1] == j) r2 = false;
            k+=2;
        }
        return !r1 && r2;
    }
};
