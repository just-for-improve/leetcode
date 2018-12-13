// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int pick = -1;
        long b = 1, e = n, mid, state;
        while (b <= e) {
            mid = (b + e) / 2;
            state = guess(mid);
            if (state == 0)
                return mid;
            if (state == 1)
                b = mid + 1;
            else
                e = mid - 1;
                
        }
        return -1;
    }
};