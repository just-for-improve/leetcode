class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));          //注意初始化dp数组的长度，以及下标i的意义
        for(int i = 0; i <= m; ++i) dp[i][0] = i;
        for(int i = 0; i <= n; ++i) dp[0][i] = i;
        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(word1[i-1] == word2[j-1])                       //word字符串的下标对应需要减一
                    dp[i][j] = dp[i-1][j-1];
                else {
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;      //状态转移方程
                }
            }
        }
        return dp[m][n];
    }
};