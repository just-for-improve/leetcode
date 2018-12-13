class Solution {
public:
    int firstUniqChar(string s) {
        int records[26];
        for (int i = 0; i < 26; ++i)
            records[i] = 0;
        for (auto ch: s)
            ++records[ch - 'a'];
        for (int i = 0; i < s.size(); ++i)
            if (records[s[i] - 'a'] == 1)
                return i;
        return -1;
    }
};