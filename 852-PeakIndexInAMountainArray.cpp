class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int mid;
        int b = 1, e = A.size() - 2;
        while (b <= e) {
            mid = (b + e) / 2;
            if (A[mid - 1] < A[mid] && A[mid] > A[mid + 1]) {
                return mid;
            } else if (A[mid - 1] < A[mid] && A[mid] < A[mid + 1]) {
                b = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return -1;
    }
};