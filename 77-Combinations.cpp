class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> path;
        vector<vector<int>> result;
        getResult(result, path, n, k);
        return result;
    }
    void getResult(vector<vector<int>> &result, vector<int> &path, int n, int k) {
        int len = path.size();
        if (len == k) {
            result.push_back(path);
            return;
        }
        int last = (len == 0 ? 0 : path[len - 1]);
        if (last == n || len + n - last < k) {
            return;
        }
        for (int i = last + 1; i <= n && i <= n - k + i; ++i) {
            vector<int> tmp = path;
            tmp.push_back(i);
            getResult(result, tmp, n, k);
        }
    }
};