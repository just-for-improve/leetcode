class Solution {
public:
    bool hasAlternatingBits(int n) {
        int flag = 1, last = -1, now;
        int i = 0;
        while (n >= flag && i < 32) {
            ++i;
            if (last == -1) {
                last = flag & n;
            } else {
                now = flag & n;
                if ((last << 1) == now) {
                    return false;
                }
                last = now;
            }
            flag = flag << 1;
        }
        return true;
    }
};