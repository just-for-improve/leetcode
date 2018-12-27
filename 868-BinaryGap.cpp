class Solution {
public:
    int binaryGap(int N) {
        int bits[32] = {0};
        int i = 0, index = 1;
        while (i < 32) {
            bits[i++] = bool(N & index);
            index <<= 1;
        }
        int b = 0, e = 0, max_dist = 0;
        while (b < 32 && e < 32) {
            while (b < 32 && bits[b] == 0) ++b;
            e = b + 1;
            while (e < 32 && bits[e] == 0) ++e;
            if (e < 32 && bits[b] == 1 && bits[e] == 1)
                max_dist = max_dist < e - b? e - b: max_dist;
            b += 1;
        }
        return max_dist;
    }
};