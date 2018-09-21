class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> map(128, 0);
        int d = INT_MAX, head = 0, begin = 0, end = 0, counter = t.size();
        for (auto ch: t) {
            ++map[ch];
        }
        while (end < s.size()) {
            if (map[s[end]] > 0) {
                --counter;
            }
            --map[s[end]];
            ++end;
            while (counter == 0) {
                if (end - begin < d) {
                    d = end - begin;
                    head = begin;
                }
                if (map[s[begin]] == 0) {
                    ++counter;
                }
                ++map[s[begin]];
                ++begin;
            }
        }
        return d == INT_MAX? "" : s.substr(head, d);
    }
};