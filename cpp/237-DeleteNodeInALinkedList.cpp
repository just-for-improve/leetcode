class Solution {
public:
    int majorityElement(vector<int>& nums) {
        stack<int> s;
        for (int i = 0; i < nums.size(); ++i) {
            if (s.empty())
                s.push(nums[i]);
            else {
                if (s.top() != nums[i])
                    s.pop();
                else
                    s.push(nums[i]);
            }
        }
        return s.top();
    }
};