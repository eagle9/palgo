// Time complexity: O(n^2)
// Running time: 6 ms
//hua and gy same idea, dp 
//grandyang code is simpler and cleaner
//runtime 16ms, faster than 97%, mem less than 35%
//cutting   dp[i][j]  max squre edge length with right bottom at i&j
/*
       expand up     expand left      cover _| space
       dp[i-1][j]    dp[i][j-1]       dp[i-1][j-1]
       1 1 1                          1 1 1
       1 1 1         1 1 1            1 1 1 
       1 1 1         1 1 1            1 1 1
          <1>        1 1 1 <1>              <1>  
          if matrix[i][j] == 1:
            dp[i][j] = min(a, b, c) + 1


*/


class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        //max square bottom right at i&j
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        int ans = 0;
        
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                if (i == 0 || j == 0) {
                    dp[i][j] = matrix[i][j] - '0';
                }else if (matrix[i][j] == '1') { //i > 0 && j > 0 
                    dp[i][j] = 1 + min( min(dp[i - 1][j - 1], dp[i - 1][j]),
                                dp[i][j - 1]);
                }
                
                ans = max(ans, dp[i][j]*dp[i][j]);
            }
        return ans;
    }
};

