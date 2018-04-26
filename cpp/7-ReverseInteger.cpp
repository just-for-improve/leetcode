class Solution {
public:
    int reverse(int x) {
        int sign = x > 0 ? 1 : -1; 
        x = (x > 0) ? x : -x;
        long result = 0;
        while (x > 0) {
            result = result * 10 + x % 10;
            x /= 10;
        }
        return sign * ((result > INT_MAX || result < INT_MIN) ? 0 : result);
    }
};
