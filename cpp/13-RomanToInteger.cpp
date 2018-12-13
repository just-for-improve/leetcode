class Solution {
public:
    int romanToInt(string s) {
        char last = ' '; 
        int sum = 0;
        for (int i = 0; i < s.size(); ++i) {
            
            char ch = s[i];
            
            if (last == ' ') {
                last = ch;
                continue;
            }
            
            
            if (last == 'I' && ch == 'V') {
                sum += 4;
                last = ' ';
            } else if (last == 'I' && ch == 'X') {
                sum += 9;
                last = ' ';
            } else if (last == 'X' && ch == 'L') {
                sum += 40;
                last = ' ';
            } else if (last == 'X' && ch == 'C') {
                sum += 90;
                last = ' ';
            } else if (last == 'C' && ch == 'D') {
                sum += 400;
                last = ' ';
            } else if (last == 'C' && ch == 'M') {
                sum += 900;
                last = ' ';
            } else {
                sum += getValue(last);
                last = ch;
            }
        }
        sum += getValue(last);
        return sum;
    }
    int getValue(char last) {
        int values[7] = {1, 5, 10, 50, 100, 500, 1000};
        char symbs[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        for (int i = 0; i < 7; ++i) {
            if (symbs[i] == last) {
                return values[i];
            }
        }
        return 0;
    }
};