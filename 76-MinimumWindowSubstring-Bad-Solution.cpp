class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size())
            return "";
        int i = 0;
        int min_len = s.size();
        int b = 0, minb = 0, mine = -1;
        int recordS[128], recordT[128];
        for (int i = 0; i < 128; ++i) {
            recordS[i] = 0;
            recordT[i] = 0;
        }
        for (auto ch: t) {
            ++recordT[ch];
            ++recordT[0];
        }
        while (i < s.size()) {
            while (i < s.size() && recordT[s[i]] == 0) ++i;
            if (recordS[0] == 0) b = i;
            ++recordS[s[i]];
            ++recordS[0];
            bool find = true;
            if (recordT[0] <= recordS[0]) {
                for (int j = 0; j < 128; ++j)
                    if(recordS[j] < recordT[j])
                        find = false;
            } else {
                find = false;
            }
            
            if (find) {
                if (i - b < min_len) {
                    min_len = i - b;
                    minb = b;
                    mine = i;
                }
                while (b <= i && i - b >= min_len) {
                    recordS[s[b]] = max(0, recordS[s[b]] - 1);
                    ++b;
                }
                while (b <= i && recordT[s[b]] == 0) ++b;
                i = b - 1;
                for (int j = 0; j < 128; ++j)
                    recordS[j] = 0;
            }
            ++i;
        }
        return string(s, minb, mine - minb + 1);
    }
};