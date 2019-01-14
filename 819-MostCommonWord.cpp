class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> map;
        unordered_set<string> set;
        transform(paragraph.begin(), paragraph.end(), paragraph.begin(), ::tolower);  
        for (int i = 0; i < paragraph.size(); ++i) {
            if (!isalpha(paragraph[i]) && paragraph[i] != ' ') {
                paragraph[i] = ' ';
            }
        }
        for (auto word: banned) {
            set.insert(word);
        }
        istringstream is(paragraph);
        int max_nu = -1;
        string tmp, max_value;
        while (is >> tmp) {
            if (set.find(tmp) == set.end()) {
                if (map.find(tmp) == map.end()) {
                    map[tmp] = 1;
                } else {
                    ++map[tmp];
                }
                if (map[tmp] > max_nu) {
                    max_nu = map[tmp];
                    max_value = tmp;
                }
            }
        }
        return max_value;
    }
};
