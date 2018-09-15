class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int i, j;
        int m = grid.size(), n = grid[0].size();
        for (i = m - 2; i >= 0; --i) {
            grid[i][n - 1] += grid[i + 1][n - 1];
        }
        for (i = n - 2; i >= 0; --i ) {
            grid[m - 1][i] += grid[m - 1][i + 1];
        }
        for (i = m - 2; i >= 0; --i) {
            for (j = n - 2; j >= 0; --j) {
                grid[i][j] += min(grid[i + 1][j], grid[i][j + 1]);
            }
        }
        return grid[0][0];
    }
};