class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if (r > 0 && c > 0 && r * c == nums.size() * nums[0].size()) {
            int count = 0;
            vector<int> tmp;
            vector<vector<int>> result;
            for (int i = 0; i < nums.size(); ++i) {
                for (int j = 0; j < nums[0].size(); ++j) {
                    tmp.push_back(nums[i][j]);
                    ++count;
                    if (count == c) {
                        result.push_back(tmp);
                        tmp.clear();
                        count = 0;
                    }
                }
            }
            return result;
        } else {
            return nums;
        }
    }
};