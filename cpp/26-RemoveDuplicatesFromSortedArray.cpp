// https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/description/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int i = 0, j = 0;
        while (j < nums.size()) {
            if (nums[i] == nums[j]) { 
                ++j;
            } else {
                swap(nums[i + 1], nums[j]);
                ++i;
                ++j;
            }
        }
        return i + 1;
    }
};
