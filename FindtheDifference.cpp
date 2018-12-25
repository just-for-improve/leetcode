class Solution {
public:
    char findTheDifference(string s, string t) {
        int records[26];
        for (int i = 0; i < 26; ++i)
            records[i] = 0;
        for (auto ch: s) {
            records[ch - 'a'] += 1;
        }
        for (auto ch: t) {
            records[ch - 'a'] -= 1;
            if (records[ch -'a'] < 0)
                return ch;
        }
        return ' ';
    }
};