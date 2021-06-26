//jz dp class idea buy sell states
//understand now, check comments and idea
//runtime 2ms, faster than 68%, memory less than 64%
class Solution {
    public int maxProfit(int[] prices) {
        if (prices == null || prices.length == 0) return 0;
        int n = prices.length;
        int [][] f = new int[n+1][5+1];
        f[0][1] = 0;
        for (int j = 2; j <=5; ++j) f[0][j] = Integer.MIN_VALUE;
        for (int i = 1; i <= n; ++i) {
            //stage 1, 3 ,5, no stock held
            //yesterday j -> today j, i means day0 to dayi-1, value change = 0
            //yesterday j-1-> today j=> means sold today(i-1th day), value change
            //f[i][j] = max{f[i-1][j], f[i-1][j-1] + Pi-1 – Pi-2}
            for (int j = 1; j <= 5; j+=2) {
                f[i][j] = f[i-1][j];
                if (i>=2 && j > 1 && f[i-1][j-1] != Integer.MIN_VALUE)
                    f[i][j] = Math.max(f[i][j], f[i-1][j-1] + prices[i-1] - prices[i-2]);
            }
            //stage 2,4,...,2K, have stock
            //yesterday j -> today j, value change = p[i-1]-p[i-2]
            //yesterday j-1 -> today j, value change = 0
            //f[i][j] = max{f[i-1][j] + Pi-1 – Pi-2, f[i-1][j-1]}
            for (int j = 2; j <= 4; j+=2) {
                f[i][j] = f[i-1][j-1]; 
                if (i >= 2 && f[i-1][j]!= Integer.MIN_VALUE)
                    f[i][j] = Math.max(f[i][j], f[i-1][j] + prices[i-1] - prices[i-2] );
            }
        }
        return Math.max(f[n][1], Math.max(f[n][3], f[n][5]));
    }
}


/*jz dp idea

f[i][j] max profit ith day (from 1) at state j = 1 to 5
i --- first i days, day 0  to day i-1
j is state that stands for how many times stock has beent traded
1 -- no stock 
2 -- have stock 1st time
3 -- sold stock 1st time
4 -- have stock 2nd time
5 -- sold stock 2nd time

recurrence equations, try to calculate profit with diff with consecutive days
check comments for more details
*/
