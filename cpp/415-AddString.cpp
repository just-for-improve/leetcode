class Solution {
public:
    string addStrings(string num1, string num2) {
        int len1 = num1.size();
        int len2 = num2.size();
        int tmp, up = 0;
        string result = "";
        while (len1 > 0 && len2 > 0) {
            --len1;
            --len2;
            tmp = num1[len1] + num2[len2] - '0' - '0';
            result = (char)((tmp + up) % 10 + '0') + result;
            up = (tmp + up) / 10;
        }
        while (len1 > 0) {
            --len1;
            result = (char)((num1[len1] - '0' + up) % 10 + '0') + result;
            up = (num1[len1] - '0' + up) / 10;
        }
        while (len2 > 0) {
            --len2;
            result = (char)((num2[len2] - '0' + up) % 10 + '0') + result;
            up = (num2[len2] - '0' + up) / 10;
            
        }
        if (up > 0)
            result = (char)(up + '0') + result;
        return result;
    }
};