class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        unordered_multiset<int> set1, set2;
        for (auto num: nums1) {
            set1.insert(num);
        }
        for (auto num: nums2) {
            if (set1.count(num) > set2.count(num)) {
                set2.insert(num);
                result.push_back(num);
            }
        }
        return result;
    }
};