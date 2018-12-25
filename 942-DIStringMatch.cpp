class Solution {
public:
    vector<int> diStringMatch(string S) {
        int value = 0, len = S.size();
        vector<int> result(len + 1, 0);
        for (int i = 0; i < len; ++i) {
            if (S[i] == 'I') {
                result[i] = value++;
            }
        }
        result[len] = value++;
        for (int i = len - 1; i >= 0; --i) {
            if (S[i] == 'D') {
                result[i] = value++;
            }
        }
        return result;
    }
};
