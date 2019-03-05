/*
Runtime: 16 ms, faster than 87.64% of C++ online submissions for 3Sum With Multiplicity.
Memory Usage: 9.4 MB, less than 67.69% of C++ online submissions for 3Sum With Multiplicity.
huahua c++ with counting and combination
*/
class Solution {
public:
  int threeSumMulti(vector<int>& A, int target) {    
    constexpr int kMaxN = 100;
    constexpr int kMod = 1e9 + 7;
    //int kMaxN = 100; //works too
    //int kMod = 1e9 + 7;
    vector<long> c(kMaxN + 1, 0); // key to use long
    
    for (int a : A) ++c[a];
    long ans = 0; //key to use long
    for (int i = 0; i <= target; ++i) {
      for (int j = i; j <= target; ++j) {
        const int k = target - i - j;
        if (k < 0 || k >= c.size() || k < j) continue;
        if (!c[i] || !c[j] || !c[k]) continue;
        if (i == j && j == k)
          ans += (c[i] - 2) * (c[i] - 1) * c[i] / 6;
        else if (i == j && j != k)
          ans += c[i] * (c[i] - 1) / 2 * c[k];
        else if (i != j && j == k)
          ans += c[i] * (c[j] - 1) * c[j] / 2;
        else
          ans += c[i] * c[j] * c[k];        
      }
    }
    return ans % kMod; //c++ no long to int conversion needed
  }
};
