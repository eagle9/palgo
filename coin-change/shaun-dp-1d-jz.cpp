//shaun read and understand jz 1d dp
//accepted first sub,  runtime 48ms, faster than 73%, mem less than 64%
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX);  //get min number of coins, init with max
        dp[0] = 0; //amount 0 can be made without any coin, or 0 coins

        //order??? from amount 1 to amount
        for (int a = 1; a <= amount; ++a) {
            //int res = INT_MAX;
            //try all coins one by one, get the min
            for (int c: coins) {
                if (c <= a) { //coin <= amount
                    int res1 = dp[a-c];
                    if (res1 != INT_MAX) {
                        dp[a] = min(dp[a], res1+1);
                    }
                    //res = min(res, dp[a -c] == INT_MAX? INT_MAX: dp[a-c]+1);  //forgot +1
                }
            }
            //dp[a] = res;  //miss this one first submission
        }

        return dp[amount] == INT_MAX? -1 : dp[amount];
    }
};

/*
test
dp[0] = 0
dp[1] = 1    1+ dp[1-1]
dp[2] = 2     1+ dp[2-1]  1+dp[2-2] = 1
dp[3] =2        1 + dp[3-1] = 3 .    1+dp[3-2] =2 
dp[4] =        1+ dp[3]=3      1+dp[2]=2 .  dp[]


*/
