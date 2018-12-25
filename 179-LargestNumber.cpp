class Solution {
public:
    string largestNumber(vector<int>& nums) {
         sort(nums.begin(), nums.end(), [](const int &value1, const int &value2) {
            string num1 = to_string(value1), num2 = to_string(value2);
            string tmp1 = num1 + num2, tmp2 = num2 + num1;
            return tmp1 > tmp2; 
        });
        string r = "";
        for (auto i: nums)
            r += to_string(i);
        int i = 0;
        while (r[i] == '0' && i + 1 < r.size())
            ++i;
        return string(r.begin() + i, r.end());
    }
};