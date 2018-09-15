class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        vector<string> tmp;
        string line, word;
        int sum = 0, count = 0, space, other, one;
        for (int k = 0; k < words.size(); ++k) {
            string word = words[k];
            if (sum < maxWidth && sum + word.size() + count <= maxWidth) {
                tmp.push_back(word);
                sum += word.size();
                count += 1;
            } else { 
                --k;
                line = "";
                if (tmp.size() != 1) {
                    space = (maxWidth - sum) / (tmp.size() - 1);
                    other = (maxWidth - sum) % (tmp.size() - 1);
                    one = 1;
                    for (int i = 0; i < tmp.size(); ++i) {
                        if (other == 0)
                            one = 0;
                        line += tmp[i];
                        if (i < tmp.size() - 1)
                            line += string(space + one, ' ');
                        --other;
                    }
                } else {
                    line += tmp[0];
                    line += string(maxWidth - tmp[0].size(), ' ');
                }
                result.push_back(line);
                tmp.clear();
                sum = 0;
                count = 0;
            }
        }
        if (tmp.size() > 0) {
            sum = tmp[0].size();
            line = tmp[0];
            for (int i = 1; i < tmp.size(); ++i) {
                line += " " + tmp[i];
                sum += (1 + tmp[i].size());
            }
            line += string(maxWidth - sum, ' ');
            result.push_back(line);
        }
        return result;
    }
};