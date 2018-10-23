class Solution
{
  public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        int m = 0, i = 0;
        while (i < flowerbed.size())
        {
            if (flowerbed[i] == 0)
            {
                if (i == 0)
                {
                    if (flowerbed[1] == 0 && (1 < flowerbed.size() && flowerbed[1] == 0 || flowerbed.size() == 1))
                    {
                        ++m;
                        i += 2;
                        continue;
                    }
                }
                else if (i == flowerbed.size() - 1)
                {
                    if (flowerbed[i - 1] == 0)
                    {
                        ++m;
                        i += 2;
                        continue;
                    }
                }
                else
                {
                    if (flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0)
                    {
                        ++m;
                        i += 2;
                        continue;
                    }
                }
            }
            ++i;
        }
        if (m >= n)
            return true;
        return false;
    }
};