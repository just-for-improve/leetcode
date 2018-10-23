class Solution
{
  public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        vector<int> result(2, 0);
        vector<short> records(nums.size() + 1, 0);

        for (auto num : nums)
        {
            ++records[num];
        }

        bool find1 = false, find2 = false;
        for (int i = 1; i < nums.size() + 1; ++i)
        {
            if (records[i] == 0)
            {
                result[1] = i;
                find1 = true;
            }
            else if (records[i] == 2)
            {
                result[0] = i;
                find2 = true;
            }
            if (find1 && find2)
                break;
        }
        return result;
    }
};