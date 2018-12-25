class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        if (nums.size() < 4) return result;
        int index3, index4;
        for (int index1 = 0; index1 < nums.size() - 3; ++index1) {
            for (int index2 = index1 + 1; index2 < nums.size() - 2; ++index2) {
                index3 = index2 + 1;
                index4 = nums.size() -1;
                while (index3 < index4) {
                    int sum = nums[index1] + nums[index2] + nums[index3] + nums[index4];
                    if (sum == target) {
                        bool insert = true;
                        vector<int> tmp{nums[index1], nums[index2], nums[index3], nums[index4]};
                        for (auto v: result) {
                            if (v == tmp) {
                                insert = false; 
                                break;
                            }
                        }
                        if (insert)
                            result.push_back(tmp);
                        ++index3;
                        --index4;
                    } else if(sum < target) {
                        ++index3;
                    } else {
                        --index4;
                    }
                }
            }
        }
        return result;
    }
};