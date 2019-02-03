class Solution {
public:
    int fib(int N) {
        int records[50];
        records[0] = 0;
        records[1] = 1;
        for (int i = 2; i <= N; ++i) {
            records[i] = records[i - 2] + records[i - 1];
        }
        return records[N];
    }
};