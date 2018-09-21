class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ips;
        if (s.size() < 4 || s.size() > 12)
            return ips;
        getIps(ips, "", s, 0, 0);
        return ips;
    }
    void getIps(vector<string>& ips, string tmp, string s, int nPoint, int loc) {
        if (loc == s.size() && nPoint == 3) {
            ips.push_back(tmp);
            return;
        }
        if ((4 - nPoint) * 3 < s.size() - loc)
            return;
        for (int i = 1; i <= 3 && loc + i <= s.size(); ++i) {
            string tmp1 = s.substr(loc, i);
            if (tmp1[0] == '0' && tmp1.size() >= 2)
                break;
            if (i == 3 && tmp1 > "255")
                break;
            string tmp2 = tmp;
            int nPointNew = nPoint;
            if (tmp != "") {
                tmp2 += ".";
                nPointNew += 1;
            }
            tmp2 += tmp1;
            getIps(ips, tmp2, s, nPointNew, loc + i);
        }
    }
};