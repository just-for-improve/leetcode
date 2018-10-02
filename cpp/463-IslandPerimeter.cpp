class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int sum = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1)
                    sum += (4 - numOfOne(grid, i, j));
            }
        }
        return sum;
    }
    int numOfOne(vector<vector<int>>& grid, int i, int j) {
        int sum = 0;
        // up
        if (i - 1 >= 0 && grid[i - 1][j] == 1)
            ++sum;
        // down
        if (i + 1 < grid.size() && grid[i + 1][j] == 1)
            ++sum;
        // left
        if (j - 1 >= 0 && grid[i][j - 1] == 1)
            ++sum;
        // right
        if (j + 1 < grid[0].size() && grid[i][j + 1] == 1)
            ++sum;
        return sum;
    }
};