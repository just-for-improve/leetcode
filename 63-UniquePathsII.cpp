class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(); 
        int n = obstacleGrid[0].size();
        if (obstacleGrid[m - 1][n - 1] == 1)
            return 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    obstacleGrid[i][j] = -1;
                }
            }
        }
        obstacleGrid[m-1][n-1] = 1;
        for (int i = m - 2; i >= 0; --i) {
            if (obstacleGrid[i][n - 1] == 0) {
                obstacleGrid[i][n - 1] = max(0, obstacleGrid[i + 1][n - 1]);
            }
        }
        for (int i = n - 2; i >= 0; --i) {
            if (obstacleGrid[m - 1][i] == 0) {
                obstacleGrid[m - 1][i] = max(0, obstacleGrid[m - 1][i + 1]);
            }
        }
        for (int i = m - 2; i >= 0; --i) {
            for (int j = n - 2; j >= 0; --j) {
                if (obstacleGrid[i][j] == 0) {
                    obstacleGrid[i][j] = max(0, obstacleGrid[i + 1][j]) + max(0, obstacleGrid[i][j + 1]);
                }
            }
        }
        return max(0, obstacleGrid[0][0]);
    }
};