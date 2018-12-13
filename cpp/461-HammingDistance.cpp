class Solution {
public:
    int hammingDistance(int x, int y) {
        int tmp = x ^ y, i = 32, sum = 0;
        while (i-- > 0) {
            sum += (tmp & 1);
            tmp >>= 1;
        }
        return sum;
    }
};