class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        int count = K, e = 0;
        string result = "";
        
        while (S[e] == '-') ++e;
        
        for (int i = S.size() - 1; i >= e; --i) {
            if (count <= 0) {
                count = K;
                result = '-' + result;
            }
            if (S[i] == '-')
                continue;
            if (S[i] >= 'a' && S[i] <= 'z')
                result = (char)toupper(S[i]) + result;
            else
                result = S[i] + result;
            --count;
        }
        return result;
    }
};