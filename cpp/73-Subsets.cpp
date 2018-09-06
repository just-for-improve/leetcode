class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> path;
        vector<int> history;
        vector<vector<int>> result(1, vector<int>());
        if (nums.size() == 0)
            return result;
        for (int i = 1; i <= nums.size(); ++i) {
            getResult(nums, result, path, history, i);
        }
        return result;
    }
    void getResult(vector<int>& nums,vector<vector<int>>& result, vector<int>& path, vector<int>& history, int n) {
        int len = path.size();
        if (len == n) {
            result.push_back(history);
            return;
        }
        int last = (len == 0? -1: path[len - 1]);
        if (last != -1 && len + nums.size() - last - 1 < n)
            return;
        for (int i = last + 1; i < nums.size(); ++i) {
            vector<int> tmp1 = path;
            vector<int> tmp2 = history;
            tmp1.push_back(i);
            tmp2.push_back(nums[i]);
            getResult(nums, result, tmp1, tmp2, n);
        }
    }
};