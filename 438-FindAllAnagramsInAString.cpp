class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = p.size();
        int records[26] = {0}, now[26] = {0};
        vector<int> result;
        if (s.size() < p.size())
            return result;
        for (auto ch: p) {
            ++records[ch - 'a'];
        }
        int l = 0, r = n - 1;
        for (int i = 0; i < n; ++i) {
            if (records[s[i] - 'a'] > 0)
                ++now[s[i] - 'a'];
        }
        while (r < s.size()) {
            bool find = true;
            for (int j = 0; j < 26; ++j) {
                if (records[j] != now[j]) {
                    find = false;
                    break;
                }
            }
            if (find)
                result.push_back(l);
            now[s[l] - 'a'] = max(0, now[s[l] - 'a'] - 1);
            ++l;
            ++r;
            if (r >= s.size())
                break;
            if (records[s[r] - 'a'] > 0)
                ++now[s[r] - 'a'];
        }
        return result;
    }
};