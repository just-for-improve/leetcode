class Solution {
public:
    vector<string> fizzBuzz(int n) {
        int flag3, flag5;
        vector<string> result;
        for (int i = 1; i <= n; ++i) {
            flag3 = i % 3;
            flag5 = i % 5;
            if (flag3 == 0 && flag5 == 0) {
                result.push_back("FizzBuzz");
            }
            else if (flag3 == 0) {
                result.push_back("Fizz");
            }
            else if (flag5 == 0) {
                result.push_back("Buzz");
            }
            else {
                result.push_back(to_string(i));
            }
        }
        return result;
    }
};