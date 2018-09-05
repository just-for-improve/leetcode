class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits.size() == 0)
            return digits;
        int up = 0;
        // add 1
        digits[digits.size() - 1] += 1;
        // deal
        for (int i = digits.size() - 1; i >= 0; --i) {
            int tmp = digits[i] + up;
            if (tmp == 0) 
                continue;
            up = tmp / 10;
            digits[i] = tmp % 10;
        }
        if (up != 0) {
            vector<int> tmp;
            tmp.push_back(up);
            for (auto digit: digits) {
                tmp.push_back(digit);
            }
            digits = tmp;
        }
        return digits;
    }
};