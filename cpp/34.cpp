class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return vector<int>{-1, -1};
        int left = 0;
        int right = nums.size() - 1;
        int mid;
        while (left <= right) {
            mid = (left + right) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                break;
            }
        }
        if (nums[mid] != target) {
            return vector<int>{-1, -1};
        }
        vector<int> result{0, nums.size() - 1};
        int i = 1;
        bool l = false, r = false;
        while (!l || !r) {
            if (!l && (nums[mid - i] != target || mid - i < 0)) {
                l = true;
                result[0] = mid - i + 1 < 0 ? 0 : mid - i + 1;
            }
            if (!r && (nums[mid + i] != target || mid + i >= nums.size())) {
                r = true;
                result[1] = mid + i - 1 >= nums.size() ? nums.size() - 1 : mid + i - 1;
            }
            
            ++i;
        }
        return result;
    }
};