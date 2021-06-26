/* Author: Huahua
Runtime: 8 ms, faster than 11.76% of C++ online submissions for Domino and Tromino Tiling.
Memory Usage: 10.2 MB
*/
class Solution {
public:
  int numTilings(int N) {
    constexpr int kMod = 1000000007;
    vector<vector<long>> dp(N + 1, vector<long>(3, 0));    
    dp[0][0] = dp[1][0] = 1;
    for (int i = 2; i <= N; ++i) {
      dp[i][0] = (dp[i - 1][0] + dp[i - 2][0] + dp[i - 1][1] + dp[i - 1][2]) % kMod;
      dp[i][1] = (dp[i - 2][0] + dp[i - 1][2]) % kMod;
      dp[i][2] = (dp[i - 2][0] + dp[i - 1][1]) % kMod;
    }
    
    return dp[N][0];
  }
};
