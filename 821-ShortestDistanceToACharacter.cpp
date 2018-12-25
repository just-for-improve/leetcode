class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        int b, e;
        vector<int> result(S.size(), -1);
        for (int i = 0; i < S.size(); ++i) {
            if (S[i] == C) {
                result[i] = 0;
                b = i - 1;
                e = i + 1;
                while (b >= 0 && (result[b] == -1 || result[b] > i - b)) {
                    result[b] = i - b--;
                }
                while (e < S.size() && (result[e] == -1 || result[e] > e - i)) {
                    result[e] = e++ - i;
                }
            }
        }
        return result;
    }
};