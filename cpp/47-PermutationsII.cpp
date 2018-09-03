class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> collection;
        vector<vector<int>> result;
        unordered_multiset<int> record, standard;
        for (auto i: nums)
            standard.insert(i);
        
        sort(nums.begin(), nums.end());
        
        getResult(collection, result, nums, record, standard);
        return result;
    }
    void getResult(vector<int> collection, vector<vector<int>> &result, 
                   vector<int>& nums, unordered_multiset<int> &record, unordered_multiset<int>& standard) {
        if (collection.size() == nums.size()) {
            result.push_back(collection);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (i < nums.size() - 1 && nums[i] == nums[i + 1])
                continue;
            if (record.count(nums[i]) + 1 > standard.count(nums[i])) {
                continue;
            }
            unordered_multiset<int> set_tmp = record;
            set_tmp.insert(nums[i]);
            vector<int> tmp = collection;
            tmp.push_back(nums[i]); 
            getResult(tmp, result, nums, set_tmp, standard);
        }
    }
};