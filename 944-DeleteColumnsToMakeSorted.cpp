class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int n = 0;
        for (int i = 0; i < A[0].size(); ++i) {
            for (int j = 0; j < A.size() - 1; ++j) {
                if (A[j][i] > A[j + 1][i]) {
                    ++n;
                    break;
                }
            }
        }
        return n;
    }
};
