class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int loc = 0, value, r = -1;
        int sum_in = 0, sum_out = 0;
        stack<int> s;
        for (int i = 0; i < nums.size(); ++i) {
            s.push(nums[i]);
            sum_in += nums[i];
        }
        for (int i = nums.size() - 1; i >=0; --i) {
            value = s.top();
            s.pop();
            sum_in -= value;
            if (sum_in == sum_out) {
                r = i;
            }
            sum_out += value;
        }
        return r;
    }
};