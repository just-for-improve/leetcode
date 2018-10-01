class Solution {
public:
    int findNthDigit(int n) {
        long width = 0, distance = 1;
        long leave = n;
        long num = 0;
        while (leave - width * distance > 0) {
            leave -= width * distance;
            ++width;
            distance = (int)pow(10, width) - (int)pow(10, width - 1);
        }
        long counter = width;
        while (--counter) {
            num = num * 10 + 9;
        }
        num += leave / width;
        int index = leave % width;
        if (index == 0)
            return num % 10;
        num += 1;
        string s = to_string(num);
        return s[index - 1] - '0';
    }
};