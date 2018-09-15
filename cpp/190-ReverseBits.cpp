class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int i = 31;
        uint32_t left = 1, right = 1, r = 0;
        right <<= 31;
        while(i > 0) {
            uint32_t tmp1 = left, tmp2 = right;
            tmp1 &= n;
            tmp2 &= n;
            tmp1 <<= i;
            tmp2 >>= i;
            r |= (tmp1 | tmp2);
            left <<= 1;
            right >>= 1;
            i -= 2;
        }
        return r;
    }
};