//shaun try with 1d dp
//amount = 0, dp[0] = 0
//amount, for all coins,   min (1 + dp[amount - coin]) for all coin
// note: no solution treatment  res1 = dp[amount - coin]
//thinking: try 1d dp first, then 2d dp
//accepted first sub, kind of slow
//runtime 1444ms, faster than 5%, mem less than 59%
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX);
        
        dp[0] = 0; //amount = 0, no coins needed
        
        for (int i = 1; i <= amount; ++i) {
            for (int coin: coins) {
                for (int k = 1; k*coin <=i; ++k) {
                    int val = k*coin;
                    if (val > i) break;
                    //val <= i
                    int res1 = dp[i - val];
                    if (res1 != INT_MAX) {
                        dp[i] = min(dp[i],k + res1);
                    }
                }
            }
        }
        return dp[amount] == INT_MAX? -1: dp[amount];
    }
};

/*
test
dp[0] = 0
dp[1] = 1    1+dp[0]  
dp[2] =2      1+dp[2-1]   2+dp[2-2]  
do[3] =       dp[3-]

*/
