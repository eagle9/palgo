/*
huahua dp
Runtime: 272 ms, faster than 55.77% of C++ online submissions for Tallest Billboard.
Memory Usage: 60.9 MB, less than 50.00% of C++ online submissions for Tallest Billboard.

*/
class Solution {
public:
  int tallestBillboard(vector<int>& rods) {
    unordered_map<int, int> dp;
    dp[0] = 0;
    for (int rod : rods) {      
      auto cur = dp;
      for (const auto& kv : cur) {
        const int k = kv.first;
        dp[k + rod] = max(dp[k + rod], cur[k]);
        dp[abs(k - rod)] = max(dp[abs(k - rod)], cur[k] + min(rod, k));
      }    
    }
    return dp[0];
  }
};
