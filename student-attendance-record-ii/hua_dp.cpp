/*
huahua dp, kind of slow
Runtime: 488 ms, faster than 5.88% of C++ online submissions for Student Attendance Record II.
*/
class Solution {
public:
  int checkRecord(int n) {
    constexpr int kMod = 1000000007;
    vector<long> dp(6, 1);
    for (int i = 1; i <= n; ++i) {
      vector<long> tmp(6);
      for (int A = 0; A <= 1; ++A)
        for (int L = 0; L <= 2; ++L) {
          const int key = getKey(A, L);
          tmp[key] += dp[getKey(A, 2)];
          if (A > 0) tmp[key] += dp[getKey(A - 1, 2)];
          if (L > 0) tmp[key] += dp[getKey(A, L - 1)];   
          tmp[key] %= kMod;
        }
      dp.swap(tmp);
    }
    return dp[5];
  }
private:
  inline int getKey(int A, int L) { return A * 3 + L; }
};
