class Solution {
public:
    int rotatedDigits(int N) {
        int result = 0;
        for (int i = 1; i <= N; ++i) {
            if (isGoodDigit(i)) {
                result += 1;
            }
        }
        return result;
    }

    bool isGoodDigit(int n) {
        int bit;
        bool diff = false;
        while (n > 0) {
            bit = n % 10;
            if (!(bit == 2 || bit == 5 || bit == 6 || bit == 9 || bit == 0 || bit == 1 || bit == 8)) {
                return false;
            }
            if (bit == 2 || bit == 5 || bit == 6 || bit == 9) {
                diff = true;
            }
            n /= 10;
        }
        return diff == true? true : false;
    }
};