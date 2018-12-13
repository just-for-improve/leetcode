class Solution {
public:
    bool wordPattern(string pattern, string str) {
        string s;
        istringstream is(str);
        unordered_map<char, string> dict1;
        unordered_map<string, char> dict2;
        for (auto ch: pattern) {
            if (!(is >> s))
                return false;
            auto iter1 = dict1.find(ch);
            auto iter2 = dict2.find(s);
            if (iter1 == dict1.end()) {
                if (iter2 == dict2.end()) {
                    dict1[ch] = s;
                    dict2[s] = ch;
                }
                else 
                    return false;
            } else {
                if (s != iter1->second)
                    return false;
                if (iter2 == dict2.end() || iter2->second != ch)
                    return false;
            }
        }
        if (is >> s)
            return false;
        return true;
    }
};