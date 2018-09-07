class Solution {
public:
    string simplifyPath(string path) {
        if (path == "")
            return "";
        stack<string> s;
        string tmp;
        for (int i = 0; i < path.size(); ++i) {
            if (path[i] == '/') {
                if (tmp != "")
                    s.push(tmp);
                tmp = "";
            } else if (path[i] == '.' && tmp == "") {
                int n = 1;
                while (i + n < path.size() && path[i + n] == '.') {
                    ++n;
                }
                if (n == 2 && (i + 2 >= path.size() || path[i + 2] == '/')) {
                    if (!s.empty())
                        s.pop();
                    ++i;
                } else if (n == 1 && (i + 1 >= path.size() || path[i + 1] == '/')) {
                    // 
                }else {
                    i += n - 1;
                    while (n--) {
                        tmp += ".";
                    }
                }
            } else {
                tmp += path[i];
            }
        }
        if (tmp != "")
            s.push(tmp);
        string result = "";
        while (!s.empty()) {
            result = "/" + s.top() + result;
            s.pop();
        }
        if (result == "")
            result = "/";
        return result;
    }
};