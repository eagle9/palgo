/*: Huahua
Runtime: 44 ms, faster than 3.45% of C++ online submissions for Flip String to Monotone Increasing.
Memory Usage: 20.2 MB, less than 1.10% of C++ online submissions for Flip String to Monotone Increasing.

huahua dp idea, my original idea is close, but i was not able to figure out a clean way. dp array dimension can be reduced.  follow up
very slow 


*/
class Solution {
public:
  int minFlipsMonoIncr(string S) {
    const int n = S.length();
    vector<vector<int>> dp(n + 1, vector<int>(2));
    for (int i = 1; i <= n; ++i) {
      if (S[i - 1] == '0') {
        dp[i][0] = dp[i - 1][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + 1;
      } else {
        dp[i][0] = dp[i - 1][0] + 1;
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]);
      }
    }
    return min(dp[n][0], dp[n][1]);
  }
};
