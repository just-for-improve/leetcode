class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        bool yes;
        int num, t;
        vector<int> digits;
        vector<int> result;
        for (int i = left; i <= right; ++i) {
            num = i;
            yes = true;
            digits.clear();
            while (num > 0) {
                t = num % 10;
                if (t == 0) {
                    yes = false;
                    break;
                }
                digits.push_back(t);
                num /= 10;
            }
            if (!yes)
                continue;
            for (auto digit: digits) {
                if (i % digit != 0) {
                    yes = false;
                    break;
                }
            }
            if (yes)
                result.push_back(i);
        }
        return result;
    }
};