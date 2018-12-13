class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        int b = 0, e = min(k - 1, n - 1), nextb = 2 * k;
        while (b < e && e < n) {
            while (b < e) {
                swap(s[b++], s[e--]);
            }
            b = nextb;
            e = min(b + k - 1, n - 1);
            nextb += 2 * k;
        }
        return s;
    }
};