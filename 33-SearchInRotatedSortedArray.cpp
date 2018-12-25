class Solution {
public:
    int search(vector<int>& nums, int target) {
        int b = 0, e = nums.size() - 1, mid_loc = 0, mid;
        while (b <= e) {
            mid = (b + e) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] >= nums[b] && target <= nums[mid] && target >= nums[b]) {
                int loc = mid_find(nums, target, b, mid);
                if (loc != -1)
                    return loc;
                e = mid - 1;
            } else if (nums[mid] >= nums[b]) {
                b = mid + 1;
            } else if (nums[mid] <= nums[e] && target >= nums[mid] && target <= nums[e]) {
                int loc = mid_find(nums, target, mid, e);
                if (loc != -1)
                    return loc;
                b = mid + 1;
            } else if (nums[mid] <= nums[e]) {
                e = mid - 1;
            }
        }
        return -1;
    }
    int mid_find(vector<int>& nums, int target, int b, int e) {
        while (b <= e) {
            int mid = (b + e) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                b = mid + 1;
            else
                e = mid - 1;
        }
        return -1;
    }
};