class Solution {
public:
    int compress(vector<char>& chars) {
        int sum = 1;
        int b = 0, e = 1;
        string str_sum;
        while (e <= chars.size()) {
            if (e ==  chars.size()) {
                if (sum > 1) {
                    str_sum = to_string(sum);
                    for (auto ch: str_sum)
                        chars[++b] = ch;
                }
                ++b;
                break;
            } else if (chars[b] != chars[e] && sum > 1) {
                str_sum = to_string(sum);
                for (auto ch: str_sum) {
                    chars[++b] = ch;
                }
                chars[++b] = chars[e++];
                sum = 1;
            } else if (chars[b] != chars[e]) {
                chars[++b] = chars[e++];
                sum = 1;
            }else if (chars[b] == chars[e]) {
                ++sum;
                ++e;
            }
        }
        return b;
    }
};