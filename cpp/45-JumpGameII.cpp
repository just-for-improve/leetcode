class Solution {
public:
    int jump(vector<int>& nums) {
        int now = 0, next = 0, counter = 0;
        while (now < nums.size() - 1) {
            int tmp = 0;
            for (int i = now; i <= now + nums[now]; ++i) {
                if (i + nums[i] > tmp || i + nums[i] >= nums.size() - 1) {
                    tmp = i + nums[i];
                    next = i;
                }
            }
            counter += 1;
            now = next;
        }
        return counter;
    }
};