// https://leetcode-cn.com/problems/pascals-triangle/description/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 0) return vector<vector<int>>{};
        vector<vector<int>> result;
        vector<int> tmp{1};
        result.push_back(tmp);
        
        for (int i = 1; i < numRows; ++i) {
            tmp.clear();
            for (int j = 0; j <= i; ++j) {
                if (j - 1 < 0) tmp.push_back(result[i-1][j]);
                else if (j >= result[i-1].size()) tmp.push_back(result[i-1][j-1]);
                else tmp.push_back(result[i-1][j-1] + result[i-1][j]);
            }
            result.push_back(tmp);
        }
        return result;
    }
};
