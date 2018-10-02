class Solution {
public:
    int arrangeCoins(int n) {
        if (n == 0)
            return 0;
        long long k = (int)sqrt(2 * (long long)n - 1);
        if ((k + 1) * k / 2 > n)
            --k;
        return k;
    }
};