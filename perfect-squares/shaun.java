/*
Runtime: 25 ms, faster than 74.77% of Java online submissions for Perfect Squares.
Memory Usage: 36.8 MB, less than 8.57% of Java online submissions for Perfect Squares.
grandyang dp idea, shaun had the same idea, but needs a little help with recurrence, ask for hint
shaun coded from memory
*/
class Solution {
    public int numSquares(int n) {
        int [] dp = new int[n+1];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[0] = 0;
        for (int i = 0; i <=n; i++) {
            for (int j = 1; i + j*j <= n; j++) {
                dp[i + j*j] = Math.min(dp[i + j*j], dp[i]+1);
            }
        }
        return dp[n];
    }
}
