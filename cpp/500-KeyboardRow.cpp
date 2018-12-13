class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string line1 = "qwertyuiop";
        string line2 = "asdfghjkl";
        string line3 = "zxcvbnm";
        int char_location[26];
        for (auto ch: line1)
            char_location[ch - 'a'] = 1;
        for (auto ch: line2)
            char_location[ch - 'a'] = 2;
        for (auto ch: line3)
            char_location[ch - 'a'] = 3;
        vector<string> result;
        int loc;
        bool find;
        for (auto word: words) {
            find = true;
            loc = char_location[tolower(word[0]) - 'a'];
            for (int i = 1; i < word.size(); ++i) {
                if (char_location[tolower(word[i]) - 'a'] != loc) {
                    find = false;
                    break;
                }
            }
            if (find)
                result.push_back(word);
        }
        return result;
    }
};