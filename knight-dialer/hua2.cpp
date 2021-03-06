/*
huahua dp 2
Runtime: 108 ms, faster than 64.54% of C++ online submissions for Knight Dialer.
Memory Usage: 31.6 MB, less than 44.68% of C++ online submissions for Knight Dialer.

*/
class Solution {
public:
  int knightDialer(int N) {
    constexpr int kMod = 1e9 + 7;
    vector<vector<int>> moves{{4,6},{8,6},{7,9},{4,8},{3,9,0},{},{1,7,0},{2,6},{1,3},{2,4}};
    vector<int> dp(10, 1);
    for (int k = 1; k < N; ++k) {
      vector<int> tmp(10);
      for (int i = 0; i < 10; ++i)
        for (int nxt : moves[i])
          tmp[nxt] = (tmp[nxt] + dp[i]) % kMod;        
      dp.swap(tmp);
    }
    int ans = 0;
    for (int i = 0; i < 10; ++i)
      ans = (ans + dp[i]) % kMod;
    return ans;
  }
};

