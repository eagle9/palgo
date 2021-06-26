/*
Runtime: 12 ms, faster than 62.09% of Java online submissions for Coin Change.
Memory Usage: 39.4 MB, less than 5.33% of Java online submissions for Coin Change.

shaun with jz dp idea
time O(amount * n_coins), space O(amount)
*/
class Solution {
    public int coinChange(int[] coins, int amount) {
        int [] dp = new int[amount+1];
        Arrays.fill(dp,Integer.MAX_VALUE);
        //get min number of coins, init with max
        dp[0] = 0; //amount 0 can be made without any coin, or 0 coins

        //order??? from amount 1 to amount
        for (int a = 1; a <= amount; ++a) {
            //int res = INT_MAX;
            //try all coins one by one, get the min
            for (int c: coins) {
                if (c <= a) { //coin <= amount
                    int res1 = dp[a-c];
                    if (res1 != Integer.MAX_VALUE) {
                        dp[a] = Math.min(dp[a], res1+1);
                    }
                    //res = min(res, dp[a -c] == INT_MAX? INT_MAX: dp[a-c]+1);  //forgot +1
                }
            }
            //dp[a] = res;  //miss this one first submission
        }

        return dp[amount] == Integer.MAX_VALUE? -1 : dp[amount];
    }
}
