class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0)
            return 0;
        unordered_set<int> s;
        unordered_multiset<int> ms;
        for (auto num: nums) {
            s.insert(num);
            ms.insert(num);
        }
        int n = 0;
        for (auto num: s) {
            if (k == 0 && ms.count(num) >= 2) {
                n += 1;
            }
            else if (k > 0 && ms.count(num - k) > 0) {
                n += 1;
            }
        }
        return n;
    }
};
