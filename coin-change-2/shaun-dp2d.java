/*
Runtime: 8 ms, faster than 31.51% of Java online submissions for Coin Change 2.
Memory Usage: 45.9 MB, less than 6.98% of Java online submissions for Coin Change 2.

shaun 2d dp, 
cutting what dp[i][j]  using coin 0 to i to make amount j

*/

class Solution {
    public int change(int amount, int[] coins) {
        if (coins.length == 0) { //add this if statment, missing this is bug 1
            if (amount == 0) return 1;
            else return 0;
        }


        int n = coins.length;
        //dp[i][j] use coin 0 to i to make amount j
        int [][] dp = new int[n][amount+1];
        //vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        //init smallest row i=0, use coins[0]
        for (int a = 0; a <= amount; ++a) {
            if (a % coins[0] == 0)
                dp[0][a] = 1;
            else
                dp[0][a] = 0;
        }
        //init smallest column, missing this init is bug 2, amount = 0
        for (int i = 0; i < n; ++i) {
            dp[i][0] = 1;
        }
        //computer order: smaller i and i-1, smaller a-coin
        for (int i = 1; i < n; ++i) {
            for (int a = 0; a <= amount; ++a) {
                //boils down two smaller problems, exclusive, use and not use
                //so no repetitive combinations, still you want to test
                dp[i][a] = dp[i - 1][a]; //not use coin[i]
                if (coins[i] <= a) //use coin[i]
                    dp[i][a] += dp[i][a - coins[i]];
            }
        }
        return dp[n-1][amount];

    }
}
