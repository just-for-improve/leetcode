class Solution {
public:
    bool detectCapitalUse(string word) {
        bool status = isupper(word[word.size() - 1]);
        for (int i = word.size() - 2; i >= 1; --i) {
            if ((bool)isupper(word[i]) != status) {
                return false;
            }
        }
        if (status == true && isupper(word[0]) == false)
            return false;
        return true;
    }
};