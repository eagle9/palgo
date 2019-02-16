// Author: Huahua
// Running time: 6 ms
class Solution {
public:
  int hammingDistance(int x, int y) {
    int ans = 0;
    int t = x^y;
    while (t) {
      ans += t & 1;
      t >>=1;
    }
    return ans;
  }
};

// Author: Huahua
// Running time: 9 ms
class Solution2 {
public:
  int hammingDistance(int x, int y) {
    return __builtin_popcount(x ^ y);
  }
};
