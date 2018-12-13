class Solution {
public:
    int totalNQueens(int n) {
        unordered_set<int> dict;
        vector<string> history(n, string(n, '.'));
        int result = 0;
        if (n == 1) 
            return 1;
        else if (n <= 3)
            return 0;
        findLocations(result, history, dict, 0, n);
        return result;
    }
    void findLocations(int& result, vector<string>& history, unordered_set<int>& dict, int which, int n) {
        if (which == n) {
            ++result;
            return;
        }
        for (int i = 0; i < n; ++i) {
            // check1
            if (dict.find(i) != dict.end()) {
                continue;
            }
            // check 2
            int loc1 = which * n + i - (n - 1);
            int loc2 = which * n + i - (n + 1);
            int line = which - 1;
            bool pass = true;
            while (loc1 >= 0 || loc2 >= 0) {
                if (loc1 >= 0 && loc1 / n == line && history[loc1 / n][loc1 % n] == 'Q') {
                    pass = false;
                    break;
                }
                if (loc2 >= 0 && loc2 / n == line && history[loc2 / n][loc2 % n] == 'Q') {
                    pass = false;
                    break;
                }
                loc1 -= (n - 1);
                loc2 -= (n + 1);
                line -= 1;
            }
            if (!pass)
                continue;
            vector<string> tmp1 = history;
            unordered_set<int> tmp2 = dict;
            tmp1[which][i] = 'Q';
            tmp2.insert(i);
            findLocations(result, tmp1, tmp2, which + 1, n);
        }
    }
};