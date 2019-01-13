class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        int b = logs.size() - 1, index = b;
        while (index >= 0 && b >= 0) {
            while (b >= 0 && isdigit(logs[b][logs[b].size() - 1])) --b;
            index = b;
            while (index >= 0 && !isdigit(logs[index][logs[index].size() - 1])) --index;
            if (index >= 0 && b >= 0)
                swap(logs[index], logs[b]);
        }
        sort(logs.begin(), logs.begin() + b + 1, [](const string& str1, const string& str2){
            int i = 0, j = 0;
            while (str1[i] != ' ') ++i;
            while (str2[j] != ' ') ++j;
            ++i; ++j;
            while (i < str1.size() && j < str2.size()) {
                if (i < str1.size() && j < str2.size() && str1[i] == str2[j]) {
                    ++i;
                    ++j;
                } else if (i < str1.size() && j < str2.size()){
                    return str1[i] < str2[j];
                }
            }
            return true;
        });
        return logs;
    }
};
