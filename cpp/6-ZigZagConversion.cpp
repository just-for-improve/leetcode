const int MAX = 100000;
class Solution {
public:
    string convert(string s, int numRows) {
        char tmp[MAX];
        int *numOfChar = new int[numRows];
        int base = MAX / (numRows + 1);
        
        memset(tmp, '\0', MAX);
        for (int i = 0; i < numRows; ++i) {
            numOfChar[i] = 0;
        }
        bool reverse = false;
        int which = 0;
        for (auto ch : s) {
            tmp[which * base + numOfChar[which]] = ch;
            numOfChar[which] += 1;
            
            if (!reverse && which < numRows - 1) {
                which += 1;
            } else if (!reverse && which == numRows - 1) {
                which -= 1;
                which = (which >= 0) ? which : 0;
                reverse = !reverse;
            } else if (reverse && which > 0) {
                which -= 1;
            } else {
                which += 1;
                which = (which < numRows - 1) ? which : numRows - 1;
                reverse = !reverse;
            }
        }
        string result = "";
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numOfChar[i]; ++j) {
                result += tmp[base * i + j];
            }
        }  
        return result;
    }
};