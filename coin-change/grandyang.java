class Solution {
    //grandyang dp idea, beats 94%, shaun java code from idea
    //fixed up several details and accepted
    public int coinChange(int[] coins, int amount) {
        //dp stores the number of coins whose sum is amount
        int [] dp = new int[amount+1];
        //initialize with a big number, assuming coin value is 1
        //the number of coins is amount, amount+1 will be max init value to be lowered
        for (int i = 0; i < amount+1; i++) {
            dp[i] = amount+1;
        }
        //the change amount is 0, how many coins you need? 0 obviously
        dp[0] = 0;
        //figure out dp for 1 to amount
        for (int i = 1; i <= amount; i++) {
            //try all coins
            for (int j = 0; j < coins.length; j++) {
                //coins[j] value <= i amount
                if (coins[j] <= i) {
                    dp[i] = Math.min(dp[i],dp[i - coins[j]]+1);
                }
            }
        }
        return dp[amount] == amount+1? -1: dp[amount];
    }
}
