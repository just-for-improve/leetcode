class Solution {
public:
    int mySqrt(int x) {
        if (x == 0)
            return 0;
        if (x == 1 || x == 2 || x == 3)
            return 1;
        long start = x / 2;
        while (start * start > x) {
            start /= 2;
        }
        while (start * start <= x) {
            start += 1;
        }
        return start - 1;
    }
};