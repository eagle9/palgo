//beats 72.20%
public class Solution {
    /**
     * @param n: an integer
     * @return: a boolean which equals to true if the first player will win
     */
    public boolean firstWillWin(int n) {
        // write your code here
        
        if (n == 0)
            return false;
        else if (n == 1)
            return true;
        else if (n == 2)
            return true;
        
        //now n > 2, dp[2] won't be index out of bound
        boolean []dp = new boolean[n+1];
        dp[0] = false;
        dp[1] = true;
        dp[2] = true;
        for (int i = 3; i <= n; i++) 
            dp[i] = !dp[i - 1] || !dp[i - 2];  // take 1 or 2
            //work on the recurrence, kind of like fibonacci, bottom up
        return dp[n];
    }

}
