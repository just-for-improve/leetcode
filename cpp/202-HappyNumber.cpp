class Solution {
public:
    bool isHappy(int n) {
        int sum = 0;
        unordered_set<int> set;
        while (n != 1) {
            if (set.find(n) != set.end())
                return false;
            set.insert(n);
            sum = 0;
            while (n) {
                sum += pow(n % 10, 2);
                n /= 10;
            }
            n = sum;
        }
        return true;
    }
};