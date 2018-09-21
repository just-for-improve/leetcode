class Solution {
public:
    string convertToBase7(int num) {
        string result = "";
        int flag = num >= 0? 1 : -1;
        num = num >= 0? num: -num;
        while (num) {
            result = to_string(num % 7) + result;
            num /= 7;
        }
        result = result == ""? "0": result;
        if (flag < 0)
            result = "-" + result;
        return result;
    }
};