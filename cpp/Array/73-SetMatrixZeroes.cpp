// https://leetcode-cn.com/problems/set-matrix-zeroes/description/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return;
        
        bool firstRow = false, firstCol = false;
        int m = matrix.size(), n = matrix[0].size();
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && matrix[i][j] == 0) {
                    firstRow = true;
                } else if (j == 0 && matrix[i][j] == 0) {
                    firstCol = true;
                } else if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j ) {
                if(i == 0 && firstRow) {
                   matrix[i][j] = 0;
                } else if (j == 0 && firstCol) {
                   matrix[i][j] = 0;
                } else {
                    if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                        matrix[i][j] = 0;
                    }
                } 
            }
        }
        
    }
};
