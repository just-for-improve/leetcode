class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        unordered_set<int> set, dict;
        for (auto i: nums1) {
            set.insert(i);
        }
        for (auto i: nums2) {
            if (set.find(i) != set.end()) {
                if (dict.find(i) == dict.end()) {
                    result.push_back(i);
                    dict.insert(i);
                }
            }
        }
        return result;
    }
};