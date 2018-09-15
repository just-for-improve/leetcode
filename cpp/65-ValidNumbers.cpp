class Solution {
public:
    bool isNumber(string s) {
        int i = 0, end = s.size() - 1;
        bool have_e = false, have_point = false, have_num = false, have_num2 = false;
        while (s[i] == ' ') ++i;
        while (s[end] == ' ') --end;
        if (i > end || ((s[i] == '+' || s[i] == '-' || s[i] == '.') && end < i + 1))
            return false;
        i = (s[i] == '+' || s[i] == '-') ? i + 1 : i;
        for (; i <= end; ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                if (have_e)
                    have_num2 = true;
                have_num = true;
                continue;
            }
            if (s[i] == '.' && have_point) 
                return false;
            if (s[i] == '.' && !have_e)
                have_point = true;
            else if (s[i] == 'e' && !have_e && have_num) {
                have_e = true;
                if (i + 1 >= s.size())
                    return false;
                if (s[i + 1] == '-' || s[i + 1] == '+')
                    ++i;
            } else {
                return false;
            }
        }
        if (have_e && !have_num2 || !have_num)
            return false;
        return true;
    }
};