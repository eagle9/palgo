//shaun 2nd try, actually quite natural for me to write this up, first and second try both clean accept
class Solution {
public:
    int uniquePaths(int m, int n) {
        //dp[i][j]  possible unique paths from 0,0 to i,j,   i from 0 to m-1, j from 0 to n-1
        vector<vector<int>> dp(m, vector<int>(n));
        
        //init 
        //first row
        for (int j = 0; j < n; ++j) dp[0][j] = 1;
        //first colum
        for (int i = 0; i < m; ++i) dp[i][0] = 1;
        
        //transition function
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
            }
        }
        return dp[m-1][n-1];
        
    }
};
