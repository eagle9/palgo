//shaun first try c++, runtime error, in java, accepted right away, runtime 0ms, faster than 100%
//int + int overflow,  change to long, accepted, leetcode has more extreme test cases
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if (m == 0) return 0;
        int n = obstacleGrid[0].size();
        if (n == 0) return 0;
        
        //int [][] dp = new int[m][n];
        vector<vector<long>> dp (m, vector<long>(n,0));
        
        if (obstacleGrid[0][0] == 0) dp[0][0] = 1;
        else {
            dp[0][0] = 0;
            return 0;
        }
        //first column
        for (int i = 1; i < m; ++i) {
            if (obstacleGrid[i][0] == 0) dp[i][0] = dp[i-1][0];
            else dp[i][0] = 0;
        }
              
        //first row
        for (int j = 1; j < n; ++j) {
            if (obstacleGrid[0][j] == 0) dp[0][j] = dp[0][j-1];
            else dp[0][j] = 0;
        }
        
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j] == 0) dp[i][j] = dp[i-1][j] + dp[i][j-1];
                else dp[i][j] = 0;
            }
        }
        return (int)dp[m-1][n-1];   //long to int cast not needed
    }
};


