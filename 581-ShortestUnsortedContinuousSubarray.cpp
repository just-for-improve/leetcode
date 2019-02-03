class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        stack<int> s;
        int start_nu = INT_MAX, end_nu = INT_MAX;
        for (auto num: nums) {
            if (s.empty() || s.top() <= num)
                s.push(num);
            else {
                while (!s.empty() && s.top() > num) {
                    s.pop();
                    start_nu = min((int)s.size(), start_nu);
                }
            }
        }
        start_nu = start_nu == INT_MAX ? nums.size() : start_nu;
        stack<int> s1;
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (s1.empty() || s1.top() >= nums[i])
                s1.push(nums[i]);
            else {
                while (!s1.empty() && s1.top() < nums[i]) {
                    s1.pop();
                    end_nu = min((int)s1.size(), end_nu);
                }
            }
                
        }
        end_nu = end_nu == INT_MAX ? nums.size() : end_nu;
        return max(0, (int)nums.size() - start_nu - end_nu);
    }
};
