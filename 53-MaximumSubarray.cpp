class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int l = 0;
        int maxSum = nums[0], sum = 0;
        while (l < nums.size()) {
            sum += nums[l];
            maxSum = max(sum, maxSum);
            if (sum <= 0) {
                sum = 0;
            } 
            ++l;
        }
        return maxSum;
    }
};
