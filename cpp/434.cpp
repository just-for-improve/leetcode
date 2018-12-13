class Solution {
public:
    int countSegments(string s) {
        int count = 0;
        string tmp;
        istringstream is(s);
        while (is >> tmp)
            ++count;
        return count;
    }
};