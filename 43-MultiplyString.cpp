class Solution {
public:
    const int MAX = 1000;
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";
        int up = 0;
        int result[MAX];
        // init
        for (int i = 0; i < MAX; ++i) {
            result[i] = 0;
        }
        // calculate
        int i, j;
        int loc, max_loc = 0;
        for (i = num1.size() - 1; i >= 0; --i) {
            for (j = num2.size() - 1; j >= 0; --j) {
                loc = num1.size() + num2.size() - 2 - i - j;
                int value = (result[loc] + (num1[i] - '0') * (num2[j] - '0') + up); 
                up = value / 10;
                result[loc] = value % 10;
            }
            loc = num1.size() + num2.size() - 2 - i - j;
            result[loc] = up;
            if (loc > max_loc) {
                max_loc = loc;
            }
            up = 0;
        }
        // result
        string r = "";
        bool start = false;
        for (int i = max_loc; i >= 0; --i) {
            if (!start && result[i] == 0) {
                continue;
            } else {
                start = true;
                r += (char)(result[i] + '0');
            }
        }
        return r;
    }
};