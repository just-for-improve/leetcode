class Solution {
public:
    string reverseWords(string s) {
        string r = "";
        stack<char> my_stack;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ' && !my_stack.empty()) {
                while (!my_stack.empty()) {
                    r += my_stack.top();
                    my_stack.pop();
                }
                r += ' ';
            } else if (s[i] == ' ' && my_stack.empty()){
                r += ' ';
            } else {
                my_stack.push(s[i]);
            }
        }
        while (!my_stack.empty()) {
            r += my_stack.top();
            my_stack.pop();
        }
        return r;
    }
};