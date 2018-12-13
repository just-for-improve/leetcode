// o(m*n)
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack.size() == 0 && needle.size() > 0 || haystack.size() < needle.size()) return -1;
        else if (haystack.size() == 0 || needle.size() == 0) return 0;
        
        int i, j;
        
        for (i = 0; i <= haystack.size() - needle.size(); ++i) {
            bool found = true;
            for (j = 0; j < needle.size(); ++j) {
                if (haystack[i + j] != needle[j]) {
                    found = false;
                    break;
                }
            }
            if (found) {
                return i;
            }
        }
        return -1;
    }
};