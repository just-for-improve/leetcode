class Solution {
public:
    bool isValid(string s) {
        stack<char> record;
        for (auto ch : s) {
            if (ch == '(' || ch == '[' || ch == '{') {
                record.push(ch);
            } else if (record.empty() && (ch == ')' || ch == ']' || ch == '}')) {
                return false;
            } else if (ch == ')' && record.top() == '(' || ch == ']' && record.top() == '[' || ch == '}' && record.top() == '{') {
                record.pop();
            } else {
                return false;
            }
        }
        return record.empty();
    }
};
