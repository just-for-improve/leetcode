class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        char ch;
        string final_addr, tmp;
        unordered_set<string> set;
        for (auto email: emails) {
            final_addr = "";
            istringstream is(email);
            while (is >> ch && ch != '+') {
                if (ch != '.')
                    final_addr += ch;
            }
            while (is >> ch && ch != '@') {
                ;
            }
            is >> tmp;
            final_addr += tmp;
            set.insert(tmp);
        }
        return set.size();
    }
};