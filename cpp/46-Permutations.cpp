class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> collection;
        vector<vector<int>> result;
        unordered_set<int> dict;
        getResult(collection, dict, result, nums);
        return result;
    }
    void getResult(vector<int> collection, unordered_set<int> dict, vector<vector<int>> &result, vector<int>& nums) {
        if (collection.size() == nums.size()) {
            result.push_back(collection);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (dict.find(nums[i]) != dict.end()) {
                continue;
            }
            unordered_set<int> dict_tmp = dict;
            dict_tmp.insert(nums[i]);
            vector<int> tmp = collection;
            tmp.push_back(nums[i]); 
            getResult(tmp, dict_tmp, result, nums);
        }
    }
};