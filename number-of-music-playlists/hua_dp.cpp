/*
hua dp
Runtime: 8 ms, faster than 96.36% of C++ online submissions for Number of Music Playlists.
Memory Usage: 11.9 MB, less than 54.29% of C++ online submissions for Number of Music Playlists.

*/
class Solution {
public:
  int numMusicPlaylists(int N, int L, int K) {
    constexpr long kMod = 1e9 + 7;
    vector<vector<long>> dp(L + 1, vector<long>(N + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= L; ++i)
      for (int j = 1; j <= min(i, N); ++j)
        dp[i][j] = (dp[i - 1][j - 1] * (N - (j - 1)) + 
                    dp[i - 1][j] * max(j - K, 0)) % kMod;    
    return dp[L][N];
  }
};
