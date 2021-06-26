//hua dp, understood, better than grandyang's dp
//shaun modified to avoid singed integer overflow for sums
//runtime 152ms, faster than 20%, mem less than 38%
class Solution {
public:
  int splitArray(vector<int>& nums, int m) {
    const int n = nums.size();
    vector<long> sums(n); //sum[i] stores sum from 0 to i
    
    sums[0] = nums[0];
    for (int j = 1; j < n; ++j)
      sums[j] = sums[j - 1] + nums[j];
      
     // dp[i][j] := min of largest sum of splitting nums[0] ~ nums[j] into i groups.
    vector<vector<int>> dp(m + 1, vector<int>(n, INT_MAX));
    //dp[1][...]   one group, sum from 0 to j
    for (int j = 0; j < n; ++j)
      dp[1][j] = sums[j];
    
    for (int i = 2; i <= m; ++i) //2 or more groups
      for (int j = i - 1; j < n; ++j) //j from i-1? why?   0 ..j into i groups, j must >= i-1, understood
        for (int k = 0; k < j; ++k) { //0 to j, k is  split
            //0 1   ..k.. j,    0 .. k to i-1 groups,  sum from k+1 to j
            int maxSum = max(dp[i - 1][k], (int)(sums[j] - sums[k]));
            dp[i][j] = min(dp[i][j], maxSum );
        }
    return dp[m][n - 1]; //m groups, 0 to n-1
  }  
};

