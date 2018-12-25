class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<int> tmp;
        vector<vector<int>> result;
        if (nums.size() < 3) return result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; ++i) {
            int index2 = i + 1;
            int index3 = nums.size() - 1;
            if (i > 0 && nums[i] == nums[i-1]) continue;
            while (index2 < index3) {
                int sum = nums[i] + nums[index2] + nums[index3];
                if (sum == 0) {
                    tmp.clear();
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[index2]);
                    tmp.push_back(nums[index3]);
                    result.push_back(tmp);
                    while (index2 + 1 < index3 && nums[index2] == nums[index2 + 1]) ++index2;
                    while (index2 < index3 - 1 && nums[index3] == nums[index3 - 1]) --index3;
                    ++index2;
                    --index3;
                } else if (sum < 0) {
                    ++index2;
                } else {
                    --index3;
                }
            }
        }
        return result;
    }
};
