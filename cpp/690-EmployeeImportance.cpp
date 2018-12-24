/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int , Employee*> dict;
        for (auto employee: employees) {
            dict[employee->id] = employee;
        }
        return func(dict, employees, id);
    }
    int func(unordered_map<int, Employee*>& dict, vector<Employee*> &employees, int id) {
        int importances = dict[id]->importance;
        for (auto subordinate: dict[id]->subordinates) {
            importances += func(dict, employees, subordinate);
        }
        return importances;
    }
};