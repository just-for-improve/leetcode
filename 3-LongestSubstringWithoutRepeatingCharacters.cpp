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

// better solution
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int mark[256];
        
        for (int i = 0; i < 256; ++i) mark[i] = -1;
        
        int i = 0, longest = 0, dist = 0, last = -1;
        
        while (i < s.size()) {
            if (mark[s[i]] == -1 || mark[s[i]] < last) {
                mark[s[i]] = i;
                ++dist;
            } else {
                longest = max(longest, dist);
                dist = i - mark[s[i]];
                last = mark[s[i]];
                mark[s[i]] = i;
            }
            ++i;
        }
        return max(longest, dist);
    }
};
