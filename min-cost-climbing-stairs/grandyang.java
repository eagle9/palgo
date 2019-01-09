/*
之前那道Climbing Stairs的拓展，这里不是求步数，而是每个台阶上都有一个cost，让我们求爬到顶端的最小cost是多少。换汤不换药，还是用动态规划Dynamic Programming来做。这里我们定义一个一维的dp数组，其中dp[i]表示爬到第i层的最小cost，然后我们来想dp[i]如何推导。我们来思考一下如何才能到第i层呢？是不是只有两种可能性，一个是从第i-2层上直接跳上来，一个是从第i-1层上跳上来。不会再有别的方法，所以我们的dp[i]只和前两层有关系，所以可以写做如下：

dp[i] = min(dp[i- 2] + cost[i - 2], dp[i - 1] + cost[i - 1])

最后我们返回最后一个数字dp[n]即可
grandyang idea 1, shaun java code, beats 45%
*/
class Solution1 {
    public int minCostClimbingStairs(int[] cost) {
        int n  = cost.length;
        int [] dp = new int [n+1];
        //dp[i] is the cost to get to i
        //Once you pay the cost, you can either climb 1 or or steps.
        for (int i = 2; i <= n; i++)
            dp[i] = Math.min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
        return dp[n];
    }
}

/*
其中dp[i]表示到第i+1层的最小cost，分别初始化dp[0]和dp[1]为cost[0]和cost[1]。然后从i=2处开始遍历，此时我们的更新思路是，要爬当前的台阶，肯定需要加上当前的cost[i]，那么我们还是要从前一层或者前两层的台阶上跳上来，那么我们选择dp值小的那个，所以递归式如下：

dp[i] = cost[i] + min(dp[i- 1], dp[i - 2])

最后我们在最后两个dp值中选择一个较小的返回即可

grandyang idea2, beats 25%, different ways to come up with dp's meaning
*/
class Solution2 {
    public int minCostClimbingStairs(int [] cost) {
        int n = cost.length;
        if (n==0) return 0;
        if (n==1) return 0;
        
        int [] dp  = new int[n]; //dp[i] the min cost for getting to i+1
        
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i <n; i++) {
            dp[i] = cost[i] + Math.min(dp[i-1], dp[i-2]);
        }
        return Math.min(dp[n-1], dp[n-2]);
    }
}
/*
follow up, can you use less space? 
shaun modified from idea2, beats 37%
*/
class Solution {
     public int minCostClimbingStairs(int [] cost) {
        int n = cost.length;
        if (n==0) return 0;
        if (n==1) return 0;
        
        //dp[i] the min cost for getting to i+1
        
        int a = cost[0];
        int b = cost[1];
        for (int i = 2; i <n; i++) {
            int next = cost[i] + Math.min(a, b);
            //a b next
            a = b;
            b = next;
        }
        return Math.min(a, b);
    }
}
