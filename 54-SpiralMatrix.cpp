// https://leetcode-cn.com/problems/spiral-matrix/description/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) return vector<int> {};
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> result;
        int time1 = max((m+1)/2, m/2);
        int time2 = max((n+1)/2, n/2);
        for (int t = 0; t < min(time1, time2); ++t) {
            for (int i = t; i < n - t; ++i) {
                result.push_back(matrix[t][i]);
            }
            for (int i = t + 1; i < m - t && n-t-1 >= 0; ++i) {
                result.push_back(matrix[i][n - t - 1]);
            }
            for (int i = n - t - 2; i >= t && m-t-1>=0 && m-t-1 != t; -- i) {
                result.push_back(matrix[m - t - 1][i]);
            }
            for (int i = m - t - 2; i > t && t != n-t-1; --i) {
                result.push_back(matrix[i][t]);
            }
        }
        return result;
    }
};
