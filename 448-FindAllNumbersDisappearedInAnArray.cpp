class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int loc = 0;
        while (loc < nums.size()) {
            if (nums[nums[loc] - 1] != nums[loc]) {
                swap(nums[nums[loc] - 1], nums[loc]);
            } else {
                ++loc;
            }
        }
        vector<int> result;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i + 1) {
                result.push_back(i + 1);
            }
        }
        return result;
    }
};