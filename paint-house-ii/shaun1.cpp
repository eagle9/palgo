//shaun first try, wrong answer, find min1 and min2 not correct
//use idx for min1 and min2
class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size(); //number of houses
        if (n == 0) return 0;
        int k = costs[0].size(); //number of colors
        if (k == 0) return 0;
        
        vector<vector<int>> dp(n,vector<int>(k, INT_MAX));
        //dp[i][j] the cost accumulative of painting house i with color j
        for (int j = 0; j < k; ++j) dp[0][j] = costs[0][j];
        //for house 1 to n-1
        for (int i = 1; i < n; ++i) {
            
            int min1 = INT_MAX, min2 = INT_MAX;
            int imin1 = -1, imin2 = -1;
            for (int j = 0; j < k; ++j) {
                if (costs[i-1][j] < min1) {
                    min1 = costs[i-1][j];
                    imin1 = j;
                }
                
            }
            //find min2 that exclude min1
            for (int j = 0; j < k; ++j) {
                if (j == imin1) continue;
                if (costs[i-1][j] < min2) {
                    min2 = costs[i-1][j];
                    imin2 = j;
                }
                //min2 = min(min2, costs[i-1][j]);
            }
            
            //try color 0 to k
            for (int j = 0; j < k; ++j) {
                //dp[i][j] = costs[i][j] + min --- dp[i-1][jj: jj!=j]
                //to find min dp[i-1][0..k] exclude j
                //if (min1 != costs[i-1][j])
                if (imin1 != j)
                    dp[i][j] =  min(dp[i][j],costs[i][j] + min1 );
                else {
                    dp[i][j] = min(dp[i][j], costs[i][j] + min2);
                }
            }
        }
        int res = INT_MAX;
        //for the min cost among all colors
        for (int cost: dp[n-1]) res = min(res, cost);
        return res;
    }
};

//shaun checked with jz, borrowed code to find min1 and min2
//runtime 16ms, faster than 87%
class Solution1 {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size(); //number of houses
        if (n == 0) return 0;
        int k = costs[0].size(); //number of colors
        if (k == 0) return 0;
        
        vector<vector<int>> dp(n,vector<int>(k, INT_MAX));
        //dp[i][j] the cost accumulative of painting house i with color j
        for (int j = 0; j < k; ++j) dp[0][j] = costs[0][j];
        //for house 1 to n-1
        int a,b;
        for (int i = 1; i < n; ++i) {
            
            // find minimum and 2nd minimum among
            // f[i-1][0], ..., f[i - 1][K - 1]
            a = b = -1;
            for (int j = 0; j < k; ++j) {
                if (a == -1 || dp[i - 1][j] < dp[i - 1][a]) {
                    b = a; // old minimum is now 2nd minimum
                    a = j; // new minimum is f[i-1][k]
                }
                else {
                    if (b == -1 || dp[i - 1][j] < dp[i - 1][b]) {
                        b = j;
                    }
                }
            }
            
            //try color 0 to k
            for (int j = 0; j < k; ++j) {
                //dp[i][j] = costs[i][j] + min --- dp[i-1][jj: jj!=j]
                //to find min dp[i-1][0..k] exclude j
                if (j != a) //j is not min
                //if (costs[i-1][j] != costs[i-1][a]) //can compare with value???
                    dp[i][j] =  min(dp[i][j],costs[i][j] + dp[i-1][a]);
                else {
                    dp[i][j] = min(dp[i][j], costs[i][j] + dp[i-1][b]);
                }
            }
        }
        int res = INT_MAX;
        //for the min cost among all colors
        for (int cost: dp[n-1]) res = min(res, cost);
        return res;
    }
};
