class Solution {
public:
    string convertToTitle(int n) {
        string result = "";
        while (n > 0) {
            int ch = (n - 1) % 26;
            result = (char)('A' + ch) + result;
            n = (n - 1) / 26;
        }
        return result;
    }
};