class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        
        bool start = true;
        int r, distance;
        int s, p, e;
        
        for (int s = 0; s < nums.size() - 2; ++s) {
            p = s + 1;
            e = nums.size() - 1;
            
            while (p < e) {
                int sum = nums[s] + nums[p] + nums[e];
                if (start) {
                    start = false;
                    r = sum;
                    distance = abs(target - sum);
                } else {
                    if (abs(sum - target) < distance) {
                        distance = abs(sum - target);
                        r = sum;
                    }
                }
                if (sum == target) {
                    return sum;
                } else if (sum < target) {
                    p++;
                } else {
                    e--;
                }
            }
        }
        return r;
    }
};