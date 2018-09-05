class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<int> tmp(n, 0);
        vector<vector<int>> result(n, tmp);
        int now = 1;
        for (int i = 0; i <= n / 2; ++i) {
            // to right
            for (int m = i; m < n - i; ++m) {
                result[i][m] = now++;
            }
            // down
            for (int m = i + 1; m < n - i; ++m) {
                result[m][n - i - 1] = now++;
            }
            // left
            for (int m = i + 1; m < n - i; ++m) {
                result[n - i - 1][n - m - 1] = now++;
            }
            // up
            for (int m = i + 1; m < n - i - 1; ++m) {
                result[n - m - 1][i] = now++;
            }
        }
        return result;
    }
};