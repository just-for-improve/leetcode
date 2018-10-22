struct Person
{
    Person(int g, int l) : grade(g), location(l) {}
    int grade;
    int location;
};

class Solution
{
  public:
    vector<string> findRelativeRanks(vector<int> &nums)
    {
        vector<Person> persons;
        for (int i = 0; i < nums.size(); ++i)
        {
            persons.push_back(Person(nums[i], i));
        }
        sort(persons.begin(), persons.end(), [](const Person &p1, const Person &p2) { return p1.grade > p2.grade; });

        vector<string> result(nums.size(), "");
        for (int i = 0; i < persons.size(); ++i)
        {
            if (i == 0)
                result[persons[i].location] = "Gold Medal";
            else if (i == 1)
                result[persons[i].location] = "Silver Medal";
            else if (i == 2)
                result[persons[i].location] = "Bronze Medal";
            else
                result[persons[i].location] = to_string(i + 1);
        }
        return result;
    }
};