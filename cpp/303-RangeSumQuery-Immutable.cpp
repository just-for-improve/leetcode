class NumArray {
public:
    NumArray(vector<int> nums) {
        int sum = 0;
        for (auto num: nums) {
            sum += num;
            psum.push_back(sum);
        }
    }
    int sumRange(int i, int j) {
        return psum[j] - psum[i - 1];
    }
private:
    vector<int> psum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */