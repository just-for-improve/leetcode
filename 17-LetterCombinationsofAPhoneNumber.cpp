class Solution {
public:
    unordered_map<char, vector<string>> dict;
    vector<string> letterCombinations(string digits) {
        dict['1'] = vector<string>{};
        dict['2'] = vector<string>{"a", "b", "c"};
        dict['3'] = vector<string>{"d", "e", "f"};
        dict['4'] = vector<string>{"g", "h", "i"};
        dict['5'] = vector<string>{"j", "k", "l"};
        dict['6'] = vector<string>{"m", "n", "o"};
        dict['7'] = vector<string>{"p", "q", "r", "s"};
        dict['8'] = vector<string>{"t", "u", "v"};
        dict['9'] = vector<string>{"w", "x", "y", "z"};
        dict['0'] = vector<string>{};
        vector<string> r;
        for (auto d : digits) {
            auto chs = dict[d];
            if (r.size() == 0) {
                for (auto ch : chs) {
                    r.push_back(ch);
                }
            } else {
                int now = r.size();
                for (int j = 0; j < now; ++j) {
                    for (int i = 1; i < chs.size(); ++i) {
                        r.push_back(r[j] + chs[i]);
                    }
                }
                for (int j = 0; j < now; ++j) {
                    r[j] += chs[0];
                }
            }
        }
        return r; 
    }
};
