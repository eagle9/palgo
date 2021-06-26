/* Author: Huahua DP with prefix and suffix sum
Runtime: 12 ms, faster than 100.00% of C++ online submissions for Flip String to Monotone Increasing.
Memory Usage: 11.3 MB, less than 1.66% of C++ online submissions for Flip String to Monotone Increasing.

not easy to come up. need deep understanding of the problem

*/
class Solution {
public:
  int minFlipsMonoIncr(string S) {
    const int n = S.size();
    vector<int> l(n + 1); // 1 -> 0
    vector<int> r(n + 1); // 0 -> 1
    l[0] = S[0] - '0';
    r[n - 1] = '1' - S[n - 1];
    for (int i = 1; i < n; ++i)
      l[i] = l[i - 1] + S[i] - '0';
    for (int i = n - 2; i >= 0; --i)
      r[i] = r[i + 1] + '1' - S[i];
    int ans = r[0]; // all 1s.
    for (int i = 1; i <= n; ++i)
      ans = min(ans, l[i - 1] + r[i]);
    return ans;
  }
};
