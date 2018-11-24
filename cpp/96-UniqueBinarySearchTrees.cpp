class Solution {
public:
    int cache[100100] = {0};
    int cache2[100100] = {0};
    int numTrees(int n) {
        if (cache[n]) return cache[n];
        return cache[n] = countBT(1, n);
    }
    int countBT(int b, int e) {
        if (b >= e) {
            return 1;
        }
        if (cache2[e - b]) return cache2[e - b];
        int sum = 0;
        for (int i = b; i <= e; ++i) {
            int a = countBT(b, i - 1);
            int b = countBT(i + 1, e);
            sum += a * b;
        }
        cache2[e - b] = sum;
        return sum;
    }
};