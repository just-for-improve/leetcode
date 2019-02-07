#define MAX 50000
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int start[MAX], end[MAX], times[MAX];
        for (int i = 0; i < MAX; ++i) {
            start[i] = -1;
            end[i] = -1;
            times[i] = 0;
        }
        for (int i = 0; i < nums.size(); ++i) {
            ++times[nums[i]];
            if (times[nums[i]] == 1) {
                start[nums[i]] = i;
            }
            end[nums[i]] = i;
        }
        int max_times = 0;
        for (int i = 0; i < MAX; ++i) {
            if (times[i] > max_times)
                max_times = times[i];
        }
        int min_len = INT_MAX;
        for (int i = 0; i < MAX; ++i) {
            if (times[i] == max_times) {
                if (end[i] - start[i] < min_len)
                    min_len = end[i] - start[i];
            }
        }
        return min_len + 1;
    }
};