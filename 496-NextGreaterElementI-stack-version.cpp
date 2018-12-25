class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        stack<int> s;
        unordered_map<int, int> dict;
        for (auto num: nums) {
            while (!s.empty() && s.top() < num) {
                dict[s.top()] = num;
                s.pop();
            }
            s.push(num);
        }
        vector<int> result;
        for (auto num: findNums) {
            if (dict.find(num) != dict.end())
                result.push_back(dict[num]);
            else
                result.push_back(-1);
        }
        return result;
    }
};