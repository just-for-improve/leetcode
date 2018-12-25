class Solution
{
  public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        int i = 0;
        double max_, sum = 0;
        for (; i < k; ++i)
        {
            sum += nums[i];
        }

        max_ = sum;

        for (; i < nums.size(); ++i)
        {
            sum = sum + nums[i] - nums[i - k];
            max_ = max(sum, max_);
        }
        return max_ / k;
    }
};