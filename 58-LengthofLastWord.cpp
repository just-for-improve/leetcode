class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = 0, start = s.size() - 1;
        while (start >= 0 && s[start] == ' ')
            --start;
        for (int i = start; i >= 0; --i) {
            if (s[i] == ' ') {
                return n;
            }
            ++n;
        }
        return start + 1;
    }
};