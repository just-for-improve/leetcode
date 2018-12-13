class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0, last = 0;
        for (i = 0; i < bits.size() - 1; ++i) {
            if (bits[i] == 0) {
                last = i + 1;
            }
        }
        if ((i - last) % 2 != 0)
            return false;
        return true;
    }
};