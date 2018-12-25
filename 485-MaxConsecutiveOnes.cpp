class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount = 0, nowCount = 0;
        for (auto num: nums) {
            if (num == 1)
                ++nowCount;
            else {
                maxCount = max(maxCount, nowCount);
                nowCount = 0;
            }
        }
        maxCount = max(maxCount, nowCount);
        return maxCount;
    }
};