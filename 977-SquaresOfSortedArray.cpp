class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> result;
        int i = 0;
        while (i < A.size() && A[i] < 0) ++i;
        int j = i - 1, tmp1, tmp2;
        while (j >= 0 || i < A.size()) {
            if (j >= 0 && i < A.size()) {
                tmp1 = A[i] * A[i];
                tmp2 = A[j] * A[j];
                if (tmp1 > tmp2) {
                    result.push_back(tmp2);
                    --j;
                } else {
                    result.push_back(tmp1);
                    ++i;
                }
            } else if (j >= 0) {
                result.push_back(A[j] * A[j]);
                --j;
            } else if (i < A.size()) {
                result.push_back(A[i] * A[i]);
                ++i;
            }
        }
        return result;
    }
};