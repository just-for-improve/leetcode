class Solution {
public:
    string reverseVowels(string s) {
        int b = 0, e = s.size() - 1;
        while (b < e) {
            while (b < e && !isVowel(s[b])) ++b;
            while (b < e && !isVowel(s[e])) --e;
            if (b < e) {
                swap(s[b++], s[e--]);
            }
        }
            
        return s;
    }
    bool isVowel(char ch) {
        ch = tolower(ch);
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
};