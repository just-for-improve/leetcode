class Solution {
public:
    string longestPalindrome(string s) {
        bool record[MAX][MAX];
        memset(record, 0, sizeof(record) / sizeof(bool));
        for (int i = 0; i < s.size(); ++i) {
            record[i][i] = true;
            if (s[i] == s[i + 1])
                record[i][i + 1] = true;
        }
        for (int j = 2; j < s.size(); ++j) {
            for (int i = 0;i < j; ++i) {
                if (!record[i][j] && record[i + 1][j - 1] && s[i] == s[j]) {
                        record[i][j] = true;
                }
                
            }
        }
        int mi = 0, mj = 0, mlen = 0;
        for (int i = 0; i < s.size(); ++i) {
            for (int j = i; j < s.size(); ++j) {
                if (record[i][j] && j - i > mlen) {
                    mi = i;
                    mj = j;
                    mlen = j - i;
                }
            }
        }
        return string(s, mi, mj - mi + 1);
    }
private:
    const int MAX = 1000;
};