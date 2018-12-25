class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        bool zero = true;
        int tmp, input = x;
        queue<int> record;
        while (x != 0) {
            tmp = x % 10;
            if (zero && tmp == 0) {
                x /= 10;
                continue;
            } else {
                zero = false;
            }
            record.push(tmp);
            x /= 10;
        }
        int y = 0;
        while (!record.empty()) {
            y = y * 10 + record.front();
            record.pop();
        }
        return input == y;
    }
};
