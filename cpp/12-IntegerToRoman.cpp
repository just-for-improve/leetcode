class Solution {
public:
    string intToRoman(int num) {
        // 1 10 100 1000
        int split[4] = {0};
        //               0    1    2   3   4    5    6
        //               1    5    10  50  100  500  1000
        char symbs[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        stack<char> r; 
        int i = 0;
        int tmp = 0; 
        while (num > 0) {
            tmp = num % 10;
            if (tmp == 9) {
                r.push(symbs[i + 2]);
                r.push(symbs[i]);
            } else if (tmp < 9 && tmp > 4) {
                for (int j = 0; j < tmp - 5; ++j) {
                    r.push(symbs[i]);
                }
                r.push(symbs[i + 1]);
            } else if (tmp == 4) {
                r.push(symbs[i + 1]);
                r.push(symbs[i]);
            } else {
                for (int j = 0; j < tmp; ++j) {
                    r.push(symbs[i]);
                }
            }
            i += 2;
            num /= 10;
        }
        string result = ""; 
        while (!r.empty()) {
            result += r.top(); 
            r.pop();
        }
        return result;
    }
};