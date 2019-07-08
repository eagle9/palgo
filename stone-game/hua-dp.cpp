//hua minimax dp, 
//runtime 8ms, faster than 58%, mem less than 21%
class Solution1 {
public:
  bool stoneGame(vector<int>& piles) {
    const int n = piles.size();
    // dp[i][j] := max(your_stones - op_stones) for piles[i] ~ piles[j]
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i)
      dp[i][i] = piles[i];
    for (int l = 2; l <= n; ++l)
      for (int i = 0; i < n - l + 1; ++i) {
        int j = i + l - 1;
        dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1]);
      }
    return dp[0][n - 1] > 0;    
  }
};

//space O(n)
//runtime 12ms, faster than 51%, mem less than 69%
class Solution {
public:
  bool stoneGame(vector<int>& piles) {
    const int n = piles.size();
    // dp[i] := max(your_stones - op_stones) for piles[i] to piles[i + l - 1]
    vector<int> dp(piles);    
    for (int l = 2; l <= n; ++l)
      for (int i = 0; i < n - l + 1; ++i)       
        dp[i] = max(piles[i] - dp[i + 1], piles[i + l - 1] - dp[i]);
    return dp[0] > 0;
  }
};

