class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0)
            return false;
        int Max = log(INT_MAX) / log(3);
        return ((int)pow(3, Max) % n) == 0;
    }
};