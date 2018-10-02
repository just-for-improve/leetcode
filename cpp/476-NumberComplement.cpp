class Solution {
public:
    int findComplement(int num) {
        int i = 0, neg_loc = 0, tmp = num;
        while (i++ < 32) {
            if (tmp & 1 == 1)
                neg_loc = i;
            tmp >>= 1;
        }
        num = ~num;
        num <<=(32 - neg_loc);
        num >>= (32 - neg_loc);
        return num;
    }
};