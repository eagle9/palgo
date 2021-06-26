class Solution {
    //grandyang dp idea2, beats 78%
    public int change(int amount, int[] coins) {
        //dp stores the number of combinations that make up amount
        int [] dp = new int[amount+1];
        
        
        dp[0] = 1;
        
        //for each coin
        for (int i = 0; i < coins.length; i++) {
            int coin = coins[i];
            //
            for (int j = coin; j <= amount; j++ ) {
                //accumulate combinations
                dp[j] += dp[j - coin];
            }
        }
        
        return dp[amount];
    }
}
