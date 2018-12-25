class Solution {
public:
    string addBinary(string a, string b) {
        int up = 0;
        string result = "";
        int i = a.size() - 1, j = b.size() - 1;
        while (i >= 0 && j >= 0) {
            int value = a[i] - '0' + b[j] - '0' + up;
            up = value / 2;
            result = (char)(value % 2 + '0') + result;
            --i;
            --j;
        }
        while (i >= 0) {
            int value = a[i] - '0' + up;
            up = value / 2;
            result = (char)(value % 2 + '0') + result;
            --i;
        }
        while (j >= 0) {
            int value = b[j] - '0' + up;
            up = value / 2;
            result = (char)(value % 2 + '0') + result;
            --j;
        }
        while (up > 0) {
            result = '1' + result;
            up -= 2;
        }
        return result;
    }
};