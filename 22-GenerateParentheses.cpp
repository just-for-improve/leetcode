class Solution {
public:
    vector<string> generateParenthesis(int n) {
        stack<char> filter;
        vector<string> result;
        filter.push('(');
        getResult(2 * n - 1, filter, result, "(");
        return result;
    }
    void getResult(int n, stack<char> filter, vector<string> &result, string tmp) {
        if (n == 1) {
            tmp += ")";
            if (!filter.empty() && filter.top() == '(') {
                filter.pop();
                if (filter.empty()) {
                    result.push_back(tmp);
                }
            }
            return;
        }  
        stack<char> filter_tmp = filter;

        // (
        filter.push('(');
        getResult(n - 1, filter, result, tmp + "(");
        // )
        if (!filter_tmp.empty() && filter_tmp.top() == '(') {
            filter_tmp.pop();
        } else {
            filter_tmp.push(')');
        }
        getResult(n - 1, filter_tmp, result, tmp + ")");
    }
};