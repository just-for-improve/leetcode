class Solution {
public:
    bool judgeSquareSum(int c) {
        int l = 0, r = sqrt(c), now;
        while (l <= r) {
            now = l * l + r * r;
            if (now == c)
                return true;
            else if (now < c)
                ++l;
            else  
                --r;
        }
        return false;
    }
};