class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int odd_pointer = 1, even_pointer = 0;
        while (odd_pointer < A.size() && even_pointer < A.size()) {
            while (odd_pointer < A.size() && A[odd_pointer] % 2 == 1) odd_pointer += 2;
            while (even_pointer < A.size() && A[even_pointer] % 2 == 0) even_pointer += 2;
            if (odd_pointer < A.size() && even_pointer < A.size())
                swap(A[odd_pointer], A[even_pointer]);
        }
        return A;
    }
};