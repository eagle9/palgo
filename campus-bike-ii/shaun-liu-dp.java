/*
DP: refer to https://leetcode.com/problems/campus-bikes-ii/discuss/305218/DFS-%2B-Pruning-And-DP-Solution

state : dp[i][s] = the min distance for first i workers to build the state s ,
transit: dp[i][s] = min(dp[i][s], dp[i - 1][prev] + dis(worker[i -1], bike[j)) | 0 < j <m, prev = s ^ (1 << j)
init:dp[0][0] = 0;
result: dp[n][s] s should have n bit

by
https://www.cnblogs.com/EdwardLiu/p/11617637.html

*/
class Solution {
    public int assignBikes(int[][] workers, int[][] bikes) {
        int n = workers.length;
        int m = bikes.length;
        int[][] dp = new int[n + 1][1 << m];
        for (int[] d : dp) {
            Arrays.fill(d, Integer.MAX_VALUE / 2);
        }
        dp[0][0] = 0;
        int min = Integer.MAX_VALUE;
        for (int i = 1; i <= n; i++) {
            for (int s = 1; s < (1 << m); s++) {
                for (int j = 0; j < m; j++) {
                    if ((s & (1 << j)) == 0) { // s is current state after the operation of taking bike at j, so s at j should be 1 already 
                        continue;
                    }
                    int prev = s ^ (1 << j);   // previously s at j should be 0
                    dp[i][s] = Math.min(dp[i - 1][prev] + dis(workers[i - 1], bikes[j]), dp[i][s]) ;
                    if (i == n) {
                        min = Math.min(min, dp[i][s]);
                    }
                }
            }
        }
        return min;
    }
  
    public int dis(int[] p1, int[] p2) {
        return Math.abs(p1[0] - p2[0]) + Math.abs(p1[1] - p2[1]);
    }
}
