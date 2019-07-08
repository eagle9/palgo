//shaun trying dp 2d idea
//variable i, from coin 0 to n-1
//variable j, amount 0 to amount
//j == 0, d[i][0] = 0
//i == 0, only 1 coin, d[0][j],  if j % coins[0] == 0, d[0][j] = j/coins[0]
//  else d[0][j] = -1

//transition function???
//use k*coins[i] < j
//dp[i][j] = k + dp[i-1][j - k*coins[i]]
//min for k
// dp[i][j] = min(dp[i][j], k + dp[i-1][j- k*coins[i]])
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (coins.empty()) return -1;
        
        int n = coins.size();
        //min number of coins for coins 0 to i, amount of j
        vector<vector<int>> dp(n, vector<int>(amount, INT_MAX));
        for (int j = 0; j <= amount; ++j) {
            if (j % coins[0] == 0) dp[0][j] = min(dp[0][j], j/coins[0]);
        }
        for (int i = 0; i < n; ++i) {
            dp[i][0] = 0;
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j <= amount; ++j) {
                
                    for (int k = 1; k*coins[i] < j; ++k) {
                        int res1 = dp[i-1][j- k*coins[i]];
                        if (res1 != INT_MAX)
                            dp[i][j] = min(dp[i][j], k + res1);
                    }
                
            }
        }
        
        return dp[n-1][amount] == INT_MAX? -1: dp[n-1][amount];
        
    }
};
