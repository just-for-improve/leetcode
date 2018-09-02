class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string tmp = countAndSay(n - 1);
        string result = "";
        char now = '#';
        int times = 0;
        for (auto ch: tmp) {
            if (now != ch) {
                if (now != '#') {
                    result += (times + '0');
                    result += now;
                }
                now = ch;
                times = 1;
            } else {
                ++times;
            }
        }
        result += (times + '0');
        result += now;
        return result;
    }
};