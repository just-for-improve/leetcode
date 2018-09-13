class Solution {
public:
    int titleToNumber(string s) {
        int sum = 0;
        for (auto ch: s) {
            sum *= 26;
            sum += ((int)(ch - 'A' + 1));
        }
        return sum;
    }
};