const int MAX = 10000000;
int prime[MAX];
class Solution {
public:
    int countPrimes(int n) {
        prime[0] = 0;
        prime[1] = 0;
        for (int i = 2; i <= n; ++i) {
            prime[i] = 1;
        }
        for (int i = 2; i * i < n; ++i) {
            if (prime[i]) {
                for (int j = i + i; j < n; j += i) {
                    prime[j] = 0;
                }
            }
        }
        int r = 0;
        while (n) {
            r += prime[--n];
        }
        return r;
    }
};