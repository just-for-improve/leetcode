class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int index1 = 0, index2 = numbers.size() - 1, sum;
        while (index1 < index2) {
            sum = numbers[index1] + numbers[index2];
            if (sum == target)
                return vector<int>{index1 + 1, index2 + 1};
            else if (sum < target)
                ++index1;
            else
                --index2;
        }
        return vector<int>{-1, -1};
    }
};