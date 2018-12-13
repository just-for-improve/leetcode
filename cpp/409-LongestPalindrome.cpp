class Solution {
public:
    int longestPalindrome(string s) {
        int sum = 0, odd = 0;
        int counter[128] = {0};
        for (auto ch: s)
            ++counter[ch];
        for (int i = 0; i < 128; ++i) {
            if (counter[i] % 2 == 0)
                sum += counter[i];
            else {
                sum += counter[i] - 1;
                odd += 1;
            }
        }
        if (odd > 0)
            sum += 1;
        return sum;
    }
};