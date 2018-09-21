class Solution {
public:
    bool isPowerOfFour(int num) {
        int i = 32;
        if (num == 0)
            return false;
        while (i-- > 0) {
            if (num == 1)
                return true;
            if ((num & 3) != 0)
                return false;
            num >>= 2;
        }
        return true;
    }
};