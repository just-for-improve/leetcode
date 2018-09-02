class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        // check 1
        if (words.size() == 0) {
            return vector<int>();
        }
        int wlen = words[0].size();
        // check 2
        for (auto word: words) {
           if (word.size() != wlen) {
               return vector<int>();
           }
        }
        int hash = 0;
        unordered_multiset<string> dict;
        for (auto word: words) {
            dict.insert(word);
            hash += word2int(word, wlen);
        }
        int wnu = words.size();
        vector<int> r;
        unordered_multiset<string> tmp;
        for (int i = 0; i < s.size() - wlen * wnu + 1; ++i) {
            string seq(s.begin() + i, s.begin() + i + wlen * wnu);
            if (hash != word2int(seq, wlen)) {
                continue;
            }
            int j = i;
            while (tmp.size() != wnu){
                string now(s.begin() + j, s.begin() + j + wlen);
                if (dict.find(now) != dict.end() && tmp.count(now) < dict.count(now)) {
                    tmp.insert(now);
                    j += wlen;
                } else {
                    break;
                }
            }
            if (tmp.size() == wnu) {
                r.push_back(i); 
            }
            tmp.clear();
        }
        return r;
    }
    int word2int(string w, int len){
        int r = 0;
        int i = 0;
        for (auto ch: w) {
            i += 1;
            r += ch * i;
            if (i >= len) {
                i = 0;
            }
        }
        return r;
    }
}