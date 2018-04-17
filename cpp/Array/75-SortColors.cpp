// https://leetcode-cn.com/problems/sort-colors/description/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p = 0;
        int p0 = 0, p2 = nums.size() - 1;
        while (p <= p2) {
            if (nums[p0] == 0) {
                ++p0;
                if (p0 >= p)
                    p = p0;
            } else if (nums[p2] == 2) {
                --p2;
            } else {
                if (nums[p] == 0) {
                    nums[p] = nums[p0];
                    nums[p0++] = 0;
                    if (p < p0) p = p0;
                } else if (nums[p] == 2) {
                    nums[p] = nums[p2];
                    nums[p2--] = 2;
                } else {
                    ++p;
                }
            }
        }
    }
};
