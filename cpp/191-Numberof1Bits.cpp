class Solution {
public:
    int hammingWeight(uint32_t n) {
        int sum = 0, i = 32;
        while (i) {
            if (n & 1) {
                sum += 1;
            }
            --i;
            n>>1;
        }
        return sum;
    }
};