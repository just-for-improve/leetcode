class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int index = 0;
        nums.push_back(0);
        while (index < nums.size()) {
            if (nums[index] > 0) {
                if (nums[index] != index) {
                    while (nums[index] != index && nums[index] > 0 && nums[nums[index]] != nums[index]) {
                        if (nums[index] < nums.size())
                            swap(nums[index], nums[nums[index]]);
                        else 
                            nums[index] = -1;
                    }
                }
            }
            ++index;
        }
        int i = 0;
        for (i = 1; i < nums.size(); ++i) {
            if (nums[i] != i)
                break;
        }
        return i;
    }
};