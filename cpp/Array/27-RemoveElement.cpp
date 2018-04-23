class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            while (j > 0 && nums[j] == val) --j;
            while (i < nums.size() && nums[i] != val) ++i;
            if (i < j) {
                swap(nums[i++], nums[j--]);
            }
        }
        for (i = 0; i< nums.size() && nums[i] != val; ++i);
        return i;
    }
};
