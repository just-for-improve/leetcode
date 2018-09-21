class Solution {
public:
    vector<int> grayCode(int n) {
        if (n == 0)
            return vector<int>{0};
        vector<int> tmp{0, 1};
        vector<int> codes = tmp;
        for (int i = 1; i < n; ++i) {
            codes.clear();
            for (int j = 0; j < tmp.size(); ++j) {
                codes.push_back(tmp[j] * 2);
            }
            for (int j = tmp.size() - 1; j >= 0; --j) {
                codes.push_back(tmp[j] * 2 + 1);
            }
            tmp = codes;
        }
        
        return codes;
    }
};