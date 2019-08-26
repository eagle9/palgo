/*
hua dp
Runtime: 8 ms, faster than 87.25% of C++ online submissions for Interleaving String.
Memory Usage: 9 MB, less than 100.00% of C++ online submissions for Interleaving String.

*/
class Solution {
public:
  bool isInterleave(string s1, string s2, string s3) {
    int l1 = s1.length();
    int l2 = s2.length();
    int l3 = s3.length();
    if (l1 + l2 != l3) return false;
	//key point: s1.len + s2.len == s3.len
    // dp[i][j]: whehter s3[0:i+j] is a interleva of s1[0:i] and s2[0:j]
    vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1));
    dp[0][0] = true;
    for (int i = 0; i <= l1; ++i)
      for (int j = 0; j <= l2; ++j) {        
        if (i > 0) dp[i][j] |= dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]; //take a char from s1, or take 1 char from s2
        if (j > 0) dp[i][j] |= dp[i][j - 1] && s2[j - 1] == s3[i + j - 1];        
      }
    return dp[l1][l2];
  }
};

