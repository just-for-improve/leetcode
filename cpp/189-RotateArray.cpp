class Solution {
public:
    void reverse(vector<int>& nums, int b, int e) {
        while (b < e) {
            swap(nums[b++], nums[e--]);
        }
    }
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        if (k == 0)
            return;
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
        
    }
};