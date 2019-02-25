/*
Runtime: 20 ms, faster than 77.50% of C++ online submissions for Kth Smallest Number in Multiplication Table.
Memory Usage: 8.7 MB, less than 33.33% of C++ online submissions for Kth Smallest Number in Multiplication Table.

huahua binary search, to understand

*/
class Solution {
public:
  int findKthNumber(int m, int n, int k) {
    int l = 1;
    int r = m * n + 1;
    while (l < r) {
      int x = l + (r - l) / 2;
      if (LEX(m, n, x) >= k)
        r = x;
      else
        l = x + 1;
    }
    return l;
  }
private:
  // Returns # of elements in the m*n table that are <= x
  int LEX(int m, int n, int x) {
    int count = 0;
    for (int i = 1; i <= m; ++i)
      count += min(n, x / i);
    return count;
  }
};
