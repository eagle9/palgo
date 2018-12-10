public class Solution {
    /**
     * @param costs: n x 3 cost matrix
     * @return: An integer, the minimum cost to paint all houses
     */
     //grandyang idea, not very natural to use same costs array
     //beats 78%
     //smaller problem done, how to solve the larger problem, key to DP
    public int minCost000(int[][] costs) {
            if (costs == null || costs.length == 0) {
                return 0;
            }
            
            int last = costs.length - 1; //last house index
            int [][] dp = new int[costs.length][3];
            
            //now costs[i][j]表示刷到第i+1房子用颜色j的最小花费
            for (int i = 1; i <= last; i++) {
                //use red, i-1 must use either green or blue
                costs[i][0] += Math.min(costs[i - 1][1], costs[i - 1][2]);
                //use green, i-1 must use either red or blue
                costs[i][1] += Math.min(costs[i - 1][0], costs[i - 1][2]);
                //use blue, i-1 use either red or green
                costs[i][2] += Math.min(costs[i - 1][1], costs[i - 1][0]);
            }
            
            return Math.min(Math.min(costs[last][0], costs[last][1]), costs[last][2]);
    }
    public int minCost(int [][] costs) {
        if (costs == null || costs.length == 0) {
                return 0;
        }
            
        int last = costs.length - 1; //last house index
        int [][] dp = new int[costs.length][3];
            
        for (int i = 0; i <=last; i++) {
            for (int j = 0; j <=2; j++)
                dp[i][j] = costs[i][j];
        }
        
        //now dp[i][j]表示刷到第i+1房子用颜色j的最小花费
            for (int i = 1; i <= last; i++) {
                //use red, i-1 must use either green or blue
                dp[i][0] += Math.min(dp[i - 1][1], dp[i - 1][2]);
                //use green, i-1 must use either red or blue
                dp[i][1] += Math.min(dp[i - 1][0], dp[i - 1][2]);
                //use blue, i-1 use either red or green
                dp[i][2] += Math.min(dp[i - 1][1], dp[i - 1][0]);
            }
            
            return Math.min(Math.min(dp[last][0], dp[last][1]), dp[last][2]);
    }
}
