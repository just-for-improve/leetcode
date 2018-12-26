class Solution {
public:
    int calPoints(vector<string>& ops) {
        int grade_final = 0;
        stack<int> grade;
        for (auto op: ops) {
            if (op == "C") {
                grade_final -= grade.top();
                grade.pop();
            } else if (op == "D") {
                grade_final += 2 * grade.top();
                grade.push(2 * grade.top());
            } else if (op == "+") {
                int tmp1 = grade.top();
                grade.pop();
                int this_grade = tmp1 + grade.top();
                grade_final += this_grade;
                grade.push(tmp1);
                grade.push(this_grade);
            } else {
                grade.push(stoi(op));
                grade_final += stoi(op);
            }
        }
        return grade_final;
    }
};