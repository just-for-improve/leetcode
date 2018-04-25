// bad solution
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int> set;
        int m = 0;
        for (int i = 0; i < s.size(); ++i) {
            set.clear();
            for (int j = i; j < s.size(); ++j) {
                if (set.find(s[j]) != set.end()) {
                    break;
                } else {
                    set.insert(s[j]);
                    m = max(m, j - i + 1);
                }
            }
        }
        return m;
    }
};
