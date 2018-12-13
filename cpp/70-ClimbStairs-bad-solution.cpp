class Solution {
public:
    Solution() {
        p = new long[100];
    }
    ~Solution() {
        delete[] p;
    }
    int climbStairs(int n) {
        if (n <= 0)
            return 0;
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        long a, b;
        if (p[n - 1] != 0)
            a = p[n - 1];
        else {
            a = climbStairs(n - 1);
            p[n - 1] = a;
        }
        if (p[n - 2] != 0)
            b = p[n - 2];
        else {
            b = climbStairs(n - 2);
            p[n - 2] = b;
        }
        return a + b;
    }
private:
    long *p;
};