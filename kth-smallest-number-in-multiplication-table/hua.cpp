/*
Runtime: 20 ms, faster than 77.50% of C++ online submissions for Kth Smallest Number in Multiplication Table.
Memory Usage: 8.7 MB, less than 33.33% of C++ online submissions for Kth Smallest Number in Multiplication Table.

huahua binary search, understood

*/
class Solution1 {
public:
  int findKthNumber(int m, int n, int k) {
    int l = 1;
    int r = m * n;
    while (l < r) {
      int x = l + (r - l) / 2;
      if (LEX(m, n, x) >= k) //== here, first candiate >=k
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
    //find count <= x on each row, sorted within each row
    for (int i = 1; i <= m; ++i)
      count += min(n, x / i);
    return count;
  }
};


//hua brute force, TLE
class Solution {
public:
  int findKthNumber(int m, int n, int k) {
    vector<int> s(m * n);
    //auto it = begin(s);
    auto it = s.begin(); //try not to use push_back
    for (int i = 1; i <= m; ++i)
      for (int j = 1; j <= n; ++j)
        *it++ = i * j;
    //nth_element(begin(s), begin(s) + k - 1, end(s));
    // k-1 th element at it position partitioned
    nth_element(s.begin(), s.begin() + k- 1, s.end());
    return s[k - 1];
  }
};
