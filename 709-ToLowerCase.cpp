class Solution {
public:
    string toLowerCase(string str) {
        for (auto &ch : str) {
            if (ch >= 'A' && ch <= 'Z') {
                ch = 'a' + (ch - 'A');
            }
        }
        return str;
    }
};