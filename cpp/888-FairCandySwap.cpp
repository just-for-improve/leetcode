class Solution {
public:
    // sumA - a + b = sumB + a - b
    // 2b = 2 * a + sumB - sumA
    // 2a = sumA - sumB + 2b
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        unordered_set<int> dict;
        int sum_A = 0, sum_B = 0;
        for (auto a: A) {
            sum_A += a;
            dict.insert(a);
        }
        for (auto b: B) 
            sum_B += b;
        for (auto b: B) {
            int a = (sum_A - sum_B + 2 * b) / 2;
            if (sum_A - a + b == sum_B - b + a && dict.find(a) != dict.end()) {
                return vector<int>{a, b};
            }
        }
        return vector<int>();
    }
};