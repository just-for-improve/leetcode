class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> dict;
        for (int i = 0; i < nums.size(); ++i) {
            auto iter = dict.find(nums[i]);
            if (iter == dict.end()) {
                dict[nums[i]] = vector<int>{i};
            } else {
                if (i - iter->second[iter->second.size() - 1] <= k)
                    return true;
                iter->second.push_back(i);
            }
        }
        return false;
    }
};