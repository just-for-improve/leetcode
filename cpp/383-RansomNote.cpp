class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int records[128] = {0};
        for (auto ch: ransomNote) {
            ++records[ch];
        }
        for (auto ch: magazine) {
            --records[ch];
        }
        for (int i = 0; i < 128; ++i) {
            if (records[i] > 0)
                return false;
        }
        return true;
    }
};