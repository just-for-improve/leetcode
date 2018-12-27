class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        string tmp;
        vector<string> result;
        unordered_multiset<string> dict;
        istringstream is_a(A), is_b(B);
        while (is_a >> tmp) {
            dict.insert(tmp);
        }
        while (is_b >> tmp) {
            dict.insert(tmp);
        }
        for (auto word: dict) {
            if (dict.count(word) == 1) {
                result.push_back(word);
            }
        }
        return result;
    }
};