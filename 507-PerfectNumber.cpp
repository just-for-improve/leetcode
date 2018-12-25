class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num == 1)
            return false;
        int e = sqrt(num);
        int sum = 1;
        for (int i = 2; i <= e; ++i) {
            if (num % i == 0) {
                sum += (i + num / i);
            }
        }
        if (sum == num)
            return true;
        return false;
    }
};