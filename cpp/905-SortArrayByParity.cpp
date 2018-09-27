class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int even = 0, odd = A.size() - 1;
        while (even < odd) {
            while (A[even] % 2 == 0) ++even;
            while (A[odd] %2 == 1) --odd;
            if (even < odd)
                swap(A[even++], A[odd--]); }
        return A;
    }
};