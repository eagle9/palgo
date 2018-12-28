class Solution {
    //grandyang idea 1, dp with 2d array, shaun java code, kind of translate, beats 20%
    //this idea is no good 
    public int change(int amount, int[] coins) {
        //dp stores the number of combinations using first i coins to make j amount change
        int [][] dp = new int[coins.length+1][amount+1];
        dp[0][0] = 1; //obviously 
        
        //both loop starts with 1
        for (int i =1; i <= coins.length; i++) {
            //why? makes sense, we are to figure out dp[i][j]
            dp[i][0] = 1;
            
            for (int j = 1; j <= amount; j++) {
                // one group of combinations have coins[i-1]
                // the other group of combinations do not have coins[i-1]
                //dp[i][j] = dp[i-1][j] +  (j >= coins[i-1])? dp[i][j- coins[i-1]]:0; //not working
                dp[i][j] = dp[i-1][j] +  ((j >= coins[i-1])? dp[i][j- coins[i-1]]:0); //okay
                int group1 = dp[i-1][j]; //make change amount j with coins 0 to i-1
                //why dp[i]?   make change amount j-coins[i-1] with coins 0 to i
                int group2 = (j >= coins[i-1])? dp[i][j - coins[i-1]] : 0;
                dp[i][j] = group1 + group2;
            }
        }
        return dp[coins.length][amount];
        
    }
}
