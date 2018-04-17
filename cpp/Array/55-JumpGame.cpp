// https://leetcode-cn.com/problems/jump-game/description/
// tips: find the max-reach location
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (maxReach >= nums.size() -1) return true;
            if (i == maxReach) maxReach += nums[i];
            else if (i <= maxReach) maxReach = max(maxReach, nums[i] + i);
            else return false;
        }
        return false;
    }
};
