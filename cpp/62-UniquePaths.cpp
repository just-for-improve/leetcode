class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> map(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            map[i][m - 1] = 1;
        }
        for (int i = 0; i < m; ++i) {
            map[n - 1][i] = 1;
        }
        for (int i = m - 2; i >= 0; --i) {
            for (int j = n - 2; j >= 0; --j) {
                if (map[j][i] == 0) {
                    map[j][i] = map[j][i + 1] + map[j + 1][i];
                }
            }
        }
        return map[0][0];
    }
};