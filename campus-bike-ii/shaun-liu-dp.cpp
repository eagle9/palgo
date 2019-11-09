
/*
DP: refer to https://leetcode.com/problems/campus-bikes-ii/discuss/305218/DFS-%2B-Pruning-And-DP-Solution

state : dp[i][s] = the min distance for first i workers to build the state s ,
transit: dp[i][s] = min(dp[i][s], dp[i - 1][prev] + dis(worker[i -1], bike[j)) | 0 < j <m, prev = s ^ (1 << j)
init:dp[0][0] = 0;
result: dp[n][s] s should have n bit

by
https://www.cnblogs.com/EdwardLiu/p/11617637.html

runtime 20ms, faster than 50%, mem less than 50%
*/
class Solution {
public:
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int n = workers.size();
        int m = bikes.size();
        int M = 1 << m;
        vector<vector<int>> dp(n+1,vector<int>(M, INT_MAX/2) );
        
        dp[0][0] = 0;
        int minDist = INT_MAX;
        for (int i = 1; i <= n; i++) {
            for (int s = 1; s < M; s++) {
                for (int j = 0; j < m; j++) {
                    if ((s & (1 << j)) == 0) { // s is current state after the operation of taking bike at j, so s at j should be 1 already 
                        continue;
                    }
                    int prev = s ^ (1 << j);   // previously s at j should be 0
                    dp[i][s] = min(dp[i - 1][prev] + mdist(workers[i - 1], bikes[j]), dp[i][s]) ;
                    if (i == n) {
                        minDist = min(minDist, dp[i][s]);
                    }
                }
            }
        }
        return minDist;
    }
  
    int mdist(vector<int>& p1, vector<int>& p2) {
        return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
    }
};
