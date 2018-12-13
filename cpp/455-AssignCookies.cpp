class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int count = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        for (auto provide: s) {
            if (count >= s.size() || count >= g.size())
                break;
            if (provide >= g[count])
                ++count;
        }
        return count;
    }
};