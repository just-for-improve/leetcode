class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        vector<int> hashes;
        vector<string> sorted;
        int hash;
        string tmp1;
        
        for (auto str: strs) {
            hash = getHash(str);
            
            tmp1 = str;
            sort(tmp1.begin(), tmp1.end());
            
            bool yes = false;
            
            for (int i = 0; i < hashes.size(); ++i) {
                if (hash != hashes[i])
                    continue;
                if (tmp1 == sorted[i]) {
                    yes = true;
                    result[i].push_back(str);
                    break;
                }
            }
            if (yes)
                continue;
            vector<string> tmp;
            tmp.push_back(str);
            hashes.push_back(hash);
            sorted.push_back(tmp1);
            result.push_back(tmp);
        }
        return result;
    }
    
    int getHash(string s) {
        int sum = 0;
        for (auto ch: s) {
            sum += ch;
        }
        return sum;
    }
};