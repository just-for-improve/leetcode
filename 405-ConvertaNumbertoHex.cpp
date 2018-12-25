class Solution {
public:
    string toHex(int num) {
        int i = 8;
        string result = "";
        string seq = "0123456789abcdef";
        while (i--) {
            result = seq[num & 0xf] + result;
            num >>= 4;
        }
        i = 0;
        while (result[i] == '0') ++i;
        if (i >= 8)
            return "0";
        return string(result.begin() + i, result.end());
    }
};