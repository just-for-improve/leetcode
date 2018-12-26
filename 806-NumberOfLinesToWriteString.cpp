class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int this_line = 0, nline = 1;
        for (auto ch: S) {
            if (this_line + widths[ch - 'a'] > 100) {
                this_line = widths[ch - 'a'];
                ++nline;
            } else {
                this_line += widths[ch - 'a'];
            }
        }
        return vector<int>{nline, this_line};
    }
};