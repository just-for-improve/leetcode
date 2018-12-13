class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size())
            return false;
        char map[128], record[128];
        memset(map, '\0', 128);
        memset(record, '\0', 128);
        int i = 0;
        while (i < s.size()) {
            if (map[s[i]] == '\0') {
                map[s[i]] = t[i];
                if (record[t[i]] != '\0')
                    return false;
                record[t[i]] = s[i];
            }
            else if (map[s[i]] != t[i])
                    return false;
            ++i;
        }
        return true;
    }
};