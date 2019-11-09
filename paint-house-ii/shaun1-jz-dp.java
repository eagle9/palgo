//shaun write in java from c++ idea
//c++ INT_MAX --- Integer.MAX_VALUE
// min -- Math.min
// vector<vector<int>> dp(n, vector<int>(k,INT_MAX))  --- int [][] dp = new int[n][k], loop to init, more verbose in java
//shaun checked with jz, borrowed code to find min1 and min2
//runtime 4ms, faster than 26%, mem less than 24%
class Solution {
public int minCostII(int [][] costs) {
        int n = costs.length; //number of houses
        if (n == 0) return 0;
        int k = costs[0].length; //number of colors
        if (k == 0) return 0;
        
        int [][] dp = new int [n][k]; 
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < k; ++j)
                dp[i][j] = Integer.MAX_VALUE;
        }
        
    
        //dp[i][j] the cost accumulative of painting house i with color j
        for (int j = 0; j < k; ++j) dp[0][j] = costs[0][j];
        //for house 1 to n-1
        for (int i = 1; i < n; ++i) {
            
            // find minimum and 2nd minimum among
            // dp[i-1][0], ..., dp[i - 1][k - 1]
			int a = -1; //a is the color to house i-1 minimum cost
			int b = -1; //b is the color to house i-1 2nd minimum cost
            for (int j = 0; j < k; ++j) {
				//if color j cost < min cost, b = a, a = j
                if (a == -1 || dp[i - 1][j] < dp[i - 1][a]) {
                    b = a; // old minimum is now 2nd minimum
                    a = j; // new minimum is f[i-1][k]
                }
                else { //check if color j leads cost < 2nd minimum b
                    if (b == -1 || dp[i - 1][j] < dp[i - 1][b]) {
                        b = j;
                    }
                }
            }
            
            //now color 0 to k to house i
            for (int j = 0; j < k; ++j) {
                //dp[i][j] = costs[i][j] + min --- dp[i-1][jj: jj!=j]
                //to find min dp[i-1][0..k] exclude j
                if (j != a) //color j different from color a to i-1 with min cost
                    dp[i][j] =  Math.min(dp[i][j],costs[i][j] + dp[i-1][a]);
                else { // color j same to color a to i-1 with min cost
					//derive from the cost  color b to house i-1
                    dp[i][j] = Math.min(dp[i][j], costs[i][j] + dp[i-1][b]);
                }
            }
        }
        int res = Integer.MAX_VALUE;
        //return the min cost of painting to house n-1, k cases  
        for (int cost: dp[n-1]) res = Math.min(res, cost);
        return res;
    }
};

