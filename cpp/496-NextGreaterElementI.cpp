class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        bool find;
        unordered_map<int, int> dict;
        for (int i = 0; i < nums.size(); ++i) {
            find = false;
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[j] > nums[i]) {
                    dict[nums[i]] = nums[j];
                    find = true;
                    break;
                }
            }
            if (!find) {
                dict[nums[i]] = -1;
            }
        }
        vector<int> result;
        for (auto num: findNums) {
            result.push_back(dict[num]);
        }
        return result;
    }
};