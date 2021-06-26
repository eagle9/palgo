/*
shaun's own idea and c++ and java code
Runtime: 4 ms, faster than 100.00% of C++ online submissions for Unique Paths.
Memory Usage: 8.6 MB, less than 0.96% of C++ online submissions for Unique Paths.

*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m <= 0 || n <= 0) return 1;
        //now m > 0 and n > 0
        //int dp[m+1][n+1]; or the following 
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        for (int j = 1; j <= n; ++j)  dp[1][j] = 1;
        for (int i = 1; i <= m; ++i)  dp[i][1] = 1;
        for (int i = 2; i <= m; ++i) {
            for (int j = 2; j <= n; ++j) {
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
            }
        }
        return dp[m][n]; 
    }
};

