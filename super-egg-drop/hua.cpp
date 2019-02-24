/* Author: Huahua
Runtime: 72 ms, faster than 51.35% of C++ online submissions for Super Egg Drop.
Memory Usage: 32.8 MB, less than 100.00% of C++ online submissions for Super Egg Drop.

binary search

*/
class Solution {
public:
  int superEggDrop(int K, int N) {    
    m_ = vector<vector<int>>(K + 1, vector<int>(N + 1, INT_MIN));
    return dp(K, N);
  }
private:
  // m[i][j] := min moves of i eggs and j floors
  vector<vector<int>> m_;
  
  int dp(int k, int n) {
    if (k <= 0) return 0;
    if (k == 1) return n;
    if (n <= 1) return n;
    if (m_[k][n] != INT_MIN) return m_[k][n];
        
    // broken[i]   = dp(k - 1, i - 1) is incresing with i.
    // unbroken[i] = dp(k,     n - i) is decresing with i.
    // dp[k][n] = 1 + min(max(broken[i], unbroken[i])), 1 <= i <= n
    // find the smallest i such that broken[i] >= unbroken[i],
    // which minimizes max(broken[i], unbroken[i]).
    int l = 1;
    int r = n + 1;
    while (l < r) {
      int m = l + (r - l) / 2;
      int broken = dp(k - 1, m - 1);
      int unbroken = dp(k, n - m);
      if (broken >= unbroken)
        r = m;
      else
        l = m + 1;
    }
    
    return m_[k][n] = 1 + dp(k - 1, l - 1);
  }
};
