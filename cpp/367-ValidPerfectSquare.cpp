class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num <= 0)
            return false;
        if (num == 1)
            return true;
        long b = 2, e = num / 2, mid, tmp;
        while (b <= e) {
            mid = (b + e) / 2;
            tmp = mid * mid;
            cout << tmp << endl;
            if (tmp < num)
                b = mid + 1;
            else if (tmp > num) 
                e = mid - 1;
            else
                return true;
        }
        return false;
    }
};