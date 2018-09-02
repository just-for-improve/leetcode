class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> history;
        vector<vector<int>> result; 
        if (target <= 0) {
            return result;
        }
        sort(candidates.begin(), candidates.end());
        calculate(history, result, candidates, target, 0);
        return result;
    }
    void calculate(vector<int>& history, vector<vector<int>>& result, vector<int>& candidates, int target, int index) {
        int sum = 0;
        for (auto i: history) {
            sum += i;
        }
        for (int j = index; j < candidates.size(); ++j) {
            int i = candidates[j];
            if (sum + i < target) {
                vector<int> nhistory = history;
                nhistory.push_back(i);
                calculate(nhistory, result, candidates, target, j + 1);
            } else if (sum + i > target) {
                return;
            } else {
                bool insert = true;
                vector<int> tmp = history;
                tmp.push_back(i);
                for (auto v: result) {
                    if (v == tmp) {
                        insert = false;
                    }
                }
                if (insert)
                    result.push_back(tmp);
            }
        }
    }
};