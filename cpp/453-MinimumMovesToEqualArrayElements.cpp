class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum = 0;
        int min_num = nums[0];
        for (auto &num: nums) {
            if (num < min_num)
                min_num = num;
            sum += num;
        }
        return sum - nums.size() * min_num;
    }
};