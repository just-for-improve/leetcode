class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return string();
        else if (strs.size() == 1) return strs[0];
        char ch;
        int index = 0;
        while (true) {
            ch = strs[0][index];
            for (int i = 1; i < strs.size(); ++i) {
                if (ch != strs[i][index] || strs[i].size() <= index) {
                   return string(strs[i].begin(), strs[i].begin() + index);
                }
            }
            ++index;
        }
        return string(strs[0].begin(), strs[0].begin() + index);
    }
};
