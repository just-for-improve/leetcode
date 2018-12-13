class Solution {
public:
    int longestValidParentheses(string s) {
        int max_len = 0, tmp = 0;
        stack<int> saver;
        // ( == -1
        // ) == 0
        for (auto ch: s) {
            if (ch == '(') {
               saver.push(-1);
            } else if ( ch == ')' && !saver.empty()) {
                int top = saver.top();
                if (top == -1) {
                    saver.pop();
                    saver.push(2);
                    max_len = max_len > 2? max_len: 2;
                    clean(saver, max_len);
                } else if (top > 0) {
                    saver.pop();
                    if (!saver.empty() && saver.top() == -1) {
                        saver.pop();
                        saver.push(top + 2);
                        max_len = max_len > top + 2? max_len: top + 2;
                        clean(saver, max_len);
                    } else {
                        saver.push(top);
                        max_len = max_len > top? max_len: top;
                        saver.push(0);
                    }
                }
            }
        }
        return max_len;
    }
    void clean(stack<int> &s, int &max_len) {
        int tmp;
        while (!s.empty() && s.top() > 0) {
            tmp = s.top();
            s.pop();
            if (s.empty() || s.top() <= 0) {
                s.push(tmp);
                max_len = max_len > tmp? max_len: tmp;
                break;
            } else {
                s.top() += tmp;
                max_len = max_len > s.top()? max_len: s.top();
            }
        }
    }
};