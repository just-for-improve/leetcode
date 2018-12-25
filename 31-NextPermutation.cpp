class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1) return;
        int i, j;
        bool have = false;
        for (i = nums.size() - 2; i >= 0; --i) {
            for (j = nums.size() - 1; j > i; --j)
               if (nums[i] < nums[j]) {
                   have = true;
                   break;
               }
            if (have) break;
        }
        if (have) {
            swap(nums[i], nums[j]);
            sort(nums.begin() + i + 1, nums.end());
        } else {
            sort(nums.begin(), nums.end());
        }
    }
};
