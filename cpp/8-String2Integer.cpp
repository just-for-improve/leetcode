class Solution {
public:
    int myAtoi(string str) {
        long long nu = 0;
        int symb = 1;
        bool start = false;
        
        for (auto ch : str) {
            if (!start && ch == ' ') {
                continue;
            } else if (!start && (ch == '+' || ch == '-')) {
                start = true;
                symb = ch == '+' ? 1 : -1;
            } else if (!start && (ch < '0' || ch > '9')) {
                break;
            } else if (ch >= '0' && ch <= '9') {
                start = true;
                nu = nu * 10 + ch - '0'; 
            } else if (start && (ch < '0' || ch > '9')) {
                break;
            }
            
            if (nu * symb > INT_MAX) return INT_MAX;              
            else if (nu * symb < INT_MIN) return INT_MIN;
        }
        
        return symb * nu;
    }
};
