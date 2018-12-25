class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int len = nums.size();
        int k = 3, max_num = INT_MIN, this_num, last = INT_MIN;
        if (len < nums.size()) k = 1;
        while (k-- > 0 && len > 0) {
            int i = len - 1;
            while (i > 0) {
                if (nums[i / 2] >= nums[i / 2 + 1] && nums[i / 2 + 1] < nums[i]) {
                    swap(nums[i / 2 + 1], nums[i]);
                } else if (nums[i / 2] < nums[i / 2 + 1] && nums[i / 2] < nums[i]) {
                    swap(nums[i / 2], nums[i]);
                }
                --i;
            }
            if (max_num == INT_MIN) {
                max_num = nums[0];
            }
            if (nums[0] == last) {
                ++k;
            }
            last = nums[0];
            nums[0] = nums[len - 1];
            len--;
        }
        return k < 0? last : max_num;
    }
};