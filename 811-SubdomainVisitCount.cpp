class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        int i = 0, count = 0;
        string subdomain;
        unordered_map<string, int> visit_counts;
        for (auto cpdomain: cpdomains) {
            i = 0;
            while (isdigit(cpdomain[i])) {
                ++i;
            }
            count = stoi(cpdomain.substr(0, i + 1));
            while (isspace(cpdomain[i])) {
                ++i;
            }
            do {
                if (visit_counts.find(cpdomain.substr(i)) != visit_counts.end()) {
                    visit_counts[cpdomain.substr(i)] += count;
                } else {
                    visit_counts[cpdomain.substr(i)] = count;

                }
                while (cpdomain[i] != '.') {
                    ++i;
                }
                ++i;
            } while (i < cpdomain.size());
        }
        vector<string> result;
        for (auto vc: visit_counts) {
            result.push_back(to_string(vc.second) + " " + vc.first);
        }
        return result;
    }
};