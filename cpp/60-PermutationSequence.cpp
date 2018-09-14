class Solution {
public:
    string getPermutation(int n, int k) {
        string result = "";
        for (int i = 0; i < n; ++i)
            result += (char(i + '1')); 
        while (k - 1) {
            int i, j, loc = 0;
            bool find = false;
            for (i = n - 2; i >= 0; --i) {
                char last = (char)(n + '0');
                for (j = i + 1; j < n; ++j) {
                    if (result[i] < result[j] && last >= result[j]) {
                        loc = j;
                        last = result[j];
                        find = true;
                    }
                }
                if (find) {
                    swap(result[i], result[loc]);
                    break;
                }
            }
            sort(result.begin() + i + 1, result.end());
            --k;
        }
        return result;
    }
};