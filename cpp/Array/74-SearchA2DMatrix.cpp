// https://leetcode-cn.com/problems/search-a-2d-matrix/description/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;
        int l = 0, r = matrix.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (matrix[mid][0] > target) r = mid - 1;
            else if (matrix[mid][0] < target) l = mid + 1;
            else return true;
        }
        l -= 1;
        if (l < 0 || l >= matrix.size()) return false;
        
        int s = 0, e = matrix[0].size() - 1;
        
        while (s <= e) {
            int mid = (s + e) / 2;
            if (matrix[l][mid] > target) e = mid - 1;
            else if (matrix[l][mid] < target) s = mid + 1; 
            else return true;
        }
        return false;
    }
};
