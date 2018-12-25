class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for (int i = 0; i < A.size(); ++i) {
            int b = 0, e = A[i].size() - 1;
            while (b < e) {
                swap(A[i][b++], A[i][e--]);
            }
            for (b = 0; b < A[i].size(); ++b) {
                A[i][b] ^= 1;
            }
        }
        return A;
    }
};
