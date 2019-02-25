/*
hua dp, 
Runtime: 28 ms, faster than 49.22% of C++ online submissions for Maximal Rectangle.
Memory Usage: 11.6 MB, less than 54.35% of C++ online submissions for Maximal Rectangle.
*/
class Solution {
public:
  int maximalRectangle(vector<vector<char> > &matrix) {
    int r = matrix.size();
    if (r == 0) return 0;
    int c = matrix[0].size();
  
    // dp[i][j] := max len of all 1s ends with col j at row i.
    vector<vector<int>> dp(r, vector<int>(c));
 
    for (int i = 0; i < r; ++i)
      for (int j = 0; j < c; ++j)
        dp[i][j] = (matrix[i][j] == '1') ? (j == 0 ? 1 : dp[i][j - 1] + 1) : 0;
 
    int ans = 0;
 
    for (int i = 0; i < r; ++i)
      for (int j = 0; j < c; ++j) {
        int len = INT_MAX;
        for (int k = i; k < r; k++) {
          len = min(len, dp[k][j]);
          if (len == 0) break;
          ans = max(len * (k - i + 1), ans);
        }
    }
 
    return ans;
  }
};
