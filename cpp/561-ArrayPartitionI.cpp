class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        /* solution1
        int sum = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i += 2) {
            sum += nums[i];
        }
        */
        int array[20001] = {0};
        
        for (auto num: nums) {
            ++array[num + 10000];
        }
        
        bool pass = false;
        int i = 0, j = 0, sum = 0;
        
        while (i < nums.size() / 2 && j < 20001) {
            if (array[j] == 0)
                ++j;
            else if (array[j] > 0 && !pass) {
                --array[j];
                sum += j - 10000;
                ++i;
                pass = true;
            } else {
                --array[j];
                pass = false;
            }
        }
        return sum;
    }
};