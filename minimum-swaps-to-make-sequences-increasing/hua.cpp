/* Author: Huahua

Runtime: 12 ms, faster than 100.00% of C++ online submissions for Minimum Swaps To Make Sequences Increasing.
Memory Usage: 10 MB, less than 100.00% of C++ online submissions for Minimum Swaps To Make Sequences Increasing.

*/
class Solution {
public:
  int minSwap(vector<int>& A, vector<int>& B) {
    const int n = A.size();
        
    vector<int> keep(n, INT_MAX);
    vector<int> swap(n, INT_MAX);
    
    keep[0] = 0;
    swap[0] = 1;
    
    for (int i = 1; i < n; ++i) {
      if (A[i] > A[i - 1] && B[i] > B[i - 1]) {
        // Good case, no swapping needed.
        keep[i] = keep[i - 1];
    
        // Swapped A[i - 1] / B[i - 1], swap A[i], B[i] as well
        swap[i] = swap[i - 1] + 1;
      }      
      
      if (B[i] > A[i - 1] && A[i] > B[i - 1]) {
        // A[i - 1] / B[i - 1] weren't swapped.
        swap[i] = min(swap[i], keep[i - 1] + 1);
      
        // Swapped A[i - 1] / B[i - 1], no swap needed for A[i] / B[i]      
        keep[i] = min(keep[i], swap[i - 1]);
      }      
    }
      
    return min(keep.back(), swap.back());
  }
};
