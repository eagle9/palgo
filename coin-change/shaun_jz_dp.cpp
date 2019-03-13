//jz recursion -> dp idea, shaun in c++
//Runtime: 44 ms, faster than 89.19% of C++ online submissions for Coin Change.

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX);  //get min number of coins, init with max
        dp[0] = 0; //amount 0 can be made without any coin, or 0 coins
        
        //order??? from amount 1 to amount
        for (int a = 1; a <= amount; ++a) {
            int res = INT_MAX;
            //try all coins one by one, get the min
            for (int c: coins) {
                if (a >= c) {
                    res = min(res, dp[a -c] == INT_MAX? INT_MAX: dp[a-c]+1);  //forgot +1
                }
            }
            dp[a] = res;  //miss this one first submission
        }
        
        return dp[amount] == INT_MAX? -1 : dp[amount];
        
    }
};
