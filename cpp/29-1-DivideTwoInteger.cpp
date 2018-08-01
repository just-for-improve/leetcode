// use subtraction to simulate divide
// it is too complex on time complexity
class Solution {
public:
    int divide(int dividend, int divisor) {
        int flag;
        long result = 0;
        long abs_dividend = labs(dividend), abs_divisor = labs(divisor);
        
        if (dividend == 0) return 0;
        
        if (dividend > 0 && divisor > 0 || dividend < 0 && divisor < 0) {
            flag = 1;
        } else {
            flag = -1;
        }
        if (abs_divisor == 1) { result = abs_dividend; }
        else
        while (1) {
            abs_dividend -= abs_divisor;
            if (abs_dividend >= 0) {
                result += 1;
            } else {
                break;
            }
        }
        result *= flag;
        if (result < -1 * (long)pow(2, 31) || result > (long)pow(2, 31) - 1) 
            return (long)pow(2, 31) - 1;
        else 
            return result;
    }
};