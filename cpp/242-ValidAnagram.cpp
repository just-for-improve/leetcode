class Solution {
public:
    bool isAnagram(string s, string t) {
        int records[26];
        for (int i = 0; i < 26; ++i)
            records[i] = 0;
        for (auto ch: s)
            ++records[ch - 'a'];
        for (auto ch: t) 
            --records[ch - 'a'];
        for (int i = 0; i < 26; ++i)
            if (records[i] != 0)
                return false;
        return true;
    }
};