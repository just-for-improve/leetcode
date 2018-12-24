class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        int records[10001] = {0};
        
        for (int i = 0; i < A.size(); ++i) {
            ++records[A[i]];
        }
        for (int i = 0; i < 10001; ++i) {
            if (records[i] == A.size() / 2) {
                return i;
            }
        }
        return -1; 
    }
};