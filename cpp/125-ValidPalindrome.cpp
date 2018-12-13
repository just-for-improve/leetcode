// https://leetcode-cn.com/problems/valid-palindrome/description/
class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            while (!isalnum(s[i])) ++i; 
            while (!isalnum(s[j])) --j;
            if (i >= j) break;
            if (tolower(s[i]) == tolower(s[j])) {
                ++i;
                --j;
            } else {
                return false;
            }
            
        }
        return true;
    }
};
