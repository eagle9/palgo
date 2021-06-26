//lt dp idea, great idea to come up the recurrence
//shaun grasped it, write in both java and c++
//runtime 0ms, faster than 100%
class Solution {
    public int numTrees(int n) {
        int [] dp  = new int[n+1];
        dp[0] = 1;
        dp[1] = 1;
        
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i] += dp[j-1]*dp[i-j];
            }
        }
        return dp[n];
    }
}
