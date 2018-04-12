// 9ms
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> tmp = nums;
        sort(tmp.begin(), tmp.end());
        
        int i = 0, j = tmp.size() - 1;
        while (i < j) {
            int sum = tmp[i] + tmp[j];
            if (sum > target) {
                --j;
            } else if (sum < target) {
                ++i;
            } else {
                break;
            }
        }

        int indexi, indexj;
        bool findi = false, findj = false;

        if (i < j) {
            for (int k = 0; k < nums.size(); ++k) {
                if (nums[k] == tmp[i] || nums[k] == tmp[j]) {
                    if (!findi && !findj) {
                        findi = true;
                        indexi = k;
                    } else if (!findj && findi) {
                        findj = true;
                        indexj = k;
                    } else if (findi && findj){
                        break;
                    }
                }
            }
            return vector<int> {indexi, indexj};
        }

        return vector<int> {};
    }
};


// 15ms
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i, j;
        unordered_map<int, int> map;
        
        for (int k = 0; k < nums.size(); ++k) {
            auto loc = map.find(target - nums[k]);
            if (loc != map.end()) {
                i = loc->second;
                j = k;
                break;
            } else {
                map.insert(pair<int, int>{nums[k], k});
            }
        }
        return vector<int> {i, j};
    }
};
