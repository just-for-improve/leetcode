class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> jewels;
        for (auto jewel: J) {
            jewels.insert(jewel);
        }
        int num_jewels = 0;
        for (auto stone: S) {
            if (jewels.find(stone) != jewels.end())
                ++num_jewels;
        }
        return num_jewels;
    }
};