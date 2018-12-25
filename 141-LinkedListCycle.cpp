class Solution {
public:
    double myPow(double x, int n) {
        if (n == INT_MIN) {
            return 1 / x * myPow(x, n + 1);
        }
        if (n < 0) {
            n = -n;
            x = 1 / x;
        }
        if (n == 0)
            return 1;
        else if (n == 1)
            return x;
        double value = myPow(x, n / 2);
        if (n % 2 == 0)
            return value * value;
        else
            return value * value * x;
    }
};