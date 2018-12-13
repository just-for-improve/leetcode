class Solution {
public:
    int getSum(int a, int b) {
        int up = 0, bit1, bit2;
        int index = 1, times = 32, result = 0;
        while (times-- > 0) {
            bit1 = a & index;
            bit2 = b & index;
            result = result | (bit1 ^ bit2 ^ up);
            up = (up | bit1) & bit2 || (bit1 | bit2) & up;
            up = up << (32 - times);
            index = index << 1;
        }
        return result;
    }
};