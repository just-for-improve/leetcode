class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> history;
        vector<vector<int>> result; 
        if (target <= 0) {
            return result;
        }
        sort(candidates.begin(), candidates.end());
        calculate(history, result, candidates, target);
        return result;
    }
    void calculate(vector<int>& history, vector<vector<int>>& result, vector<int>& candidates, int target) {
        int sum = 0;
        for (auto i: history) {
            sum += i;
        }
        for (auto i: candidates) {
            if (history.size() > 0 && i < history[history.size() - 1]) {
                continue;
            }
            if (sum + i < target) {
                vector<int> nhistory = history;
                nhistory.push_back(i);
                calculate(nhistory, result, candidates, target);
            } else if (sum + i > target) {
                return;
            } else {
                vector<int> tmp = history;
                tmp.push_back(i);
                result.push_back(tmp);
            }
        }
    }
};