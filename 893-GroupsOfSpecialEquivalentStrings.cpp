class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        unordered_set<string> set;
        int n = 0;
        for (auto str: A) {
            string tmp1 = "", tmp2 = "";
            for (int i = 0; i < str.size(); i += 2) {
                tmp1 += str[i];
            }
            for (int i = 1; i < str.size(); i += 2) {
                tmp2 += str[i];
            }
            sort(tmp1.begin(), tmp1.end());
            sort(tmp2.begin(), tmp2.end());
            set.insert(tmp1 + tmp2);
        }
        return set.size();
    }
};