class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<int> tmp;
        for (int i = 0; i < matrix.size() / 2; ++i) {
            tmp.clear();
            for (int m = i; m < matrix.size() - i; ++m) {
                tmp.push_back(matrix[i][m]);
            }
            // rotate
            for (int m = i + 1; m < matrix.size() - i; ++m) {
                matrix[i][matrix.size() - 1 - m] = matrix[m][i];
            }
            for (int m = i + 1; m < matrix.size() - i; ++m) {
                matrix[m][i] =  matrix[matrix.size() - 1 - i][m];
            }
            for (int m = i + 1; m < matrix.size() - i; ++m) {
                matrix[matrix.size() - 1 - i][m] =  matrix[matrix.size() - 1 - m][matrix.size() - 1 - i];
            }
            for (int m = 0; m < tmp.size(); ++m) {
                matrix[m + i][matrix.size() - 1 - i] = tmp[m];
            }
        }
    }
};