//shaun's own idea and java code, beats 49%
class Solution {
    public int climbStairs(int n) {
        //n positive integer
        int [] dp = new int[n+1];
        if (n ==1) return 1;
        if (n ==2) return 2;
        dp[1] = 1;
        dp[2] = 2;
        //dp[3] 2+ 2*1 = 4
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2]; //do some tests
        }
        return dp[n];
    }
}
