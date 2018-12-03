//shaun's own code from grandyang's c++ idea
//accepted upon first submission
//Your submission beats 85.20% Submissions!
//20181129
public class Solution {
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    public boolean firstWillWin(int[] A) {
        if (A == null || A.length == 0)
            return false;
            
        int n = A.length;
        
        if (n == 1 || n == 2)
            return true;
        if (n == 3)
            return A[0] + A[1] > A[2];
        
        //now n >= 4
        int [] dp = new int[n+1]; //dp[i] stores the first player's max value from i to the end A[n-1]
        
        dp[n]= 0; //of course
        dp[n-1] = A[n-1];
        dp[n-2] = A[n-2] + A[n-1];
        dp[n-3] = A[n-3] + A[n-2];
        //work on the recurrence
        for (int i = n-4; i>=0; i--) {
            //take A[i], opponent takes A[i+1], d[i+2]
            //take A[i], opponent takes A[i+1] & A[i+2], d[i+3]
            int max1 = A[i] + Math.min(dp[i+2], dp[i+3]);
            
            //take A[i] & A[i+1], opponent takes A[i+2], d[i+3]
            //take A[i] & A[i+1], opponent takes A[i+2] & A[i+3], d[i+4]
            int max2 = A[i] + A[i+1] + Math.min(dp[i+3], dp[i+4]);
            dp[i] = Math.max(max1, max2);
        }
        //first player's max is dp[0]
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += A[i];
        }
        //first player more?
        return dp[0] > sum - dp[0];
        
    }
}
