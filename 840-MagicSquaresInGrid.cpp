class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        if (grid.size() < 3 || grid[0].size() < 3)
            return 0;
        int n = 0;
        for (int i = 0; i < grid.size() - 2; ++i) {
            for (int j = 0; j < grid[0].size() - 2; ++j) {
                if (isMagicSquares(grid, i, j)) {
                    ++n;
                }
            }
        }
        return n;
    }
    bool isMagicSquares(vector<vector<int>>& grid, int ii, int jj) {
        int mask[10] = {0};
        
        for (int i = ii; i < ii + 3; ++i) {
            for (int j = jj; j < jj + 3; ++j) {
                if (grid[i][j] > 9 || grid[i][j] < 1)
                    return false;
                ++mask[grid[i][j]];
            }
        }
        
        for (int i = 1; i < 10; ++i) {
            if (mask[i] != 1) {
                return false;
            }
        }
        int sum = 0;
        for (int i = ii; i < ii + 3; ++i) {
            sum += grid[i][jj];
        }
        int sum1 = 0;
        for (int i = ii; i < ii + 3; ++i) {
            sum1 = 0;
            for (int j = 0; j < 3; ++j) {
                sum1 += grid[i][jj + j];
            }
            if (sum1 != sum)
                return false;
        }
        for (int i = jj; i < jj + 3; ++i) {
            sum1 = 0;
            for (int j = 0; j < 3; ++j) {
                sum1 += grid[ii + j][i];
            }
            if (sum1 != sum)
                return false;
        }
        int suml = 0, sumr = 0;
        for (int i = 0; i < 3; ++i) {
            suml += grid[ii + i][jj + i];
            sumr += grid[ii + 2 - i][jj + 2 - i];
        }
        if (suml != sum || sumr != sum)
            return false;
        
        
        return true;
    }
};
