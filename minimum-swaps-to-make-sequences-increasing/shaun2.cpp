/*
Runtime: 12 ms, faster than 100.00% of C++ online submissions for Minimum Swaps To Make Sequences Increasing.
Memory Usage: 9.7 MB, less than 100.00% of C++ online submissions for Minimum Swaps To Make Sequences Increasing.
2nd round, shaun from memory, got deeper understanding of swap[] and noSwap[] now
first submission get swap[0] wrong, should be 1, instead of 0
grandyang explains the idea better. huahua summary of dp is great. 
*/

class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int n = A.size();
        if (n != B.size()) return -1;
        
        vector<int> swap(n, n); //min swaps to keep increasing with swap at i
        vector<int> noSwap(n,n); //min swaps to keep increasing with no swap at i
        swap[0] = 1; //single number, swap at 0, still increasing
        noSwap[0] = 0;
        for (int i = 1; i < n; i++) {
            if (A[i-1] < A[i] && B[i-1] < B[i]) { 
                noSwap[i] = noSwap[i-1]; //no swap at i, no swap at i-1
                swap[i] = swap[i-1] + 1; //if swap at i, then must swap at i-1
            }
            if (A[i-1] < B[i] && B[i-1] < A[i]) {
                noSwap[i] = min(noSwap[i], swap[i-1]); //no swap at i, then must swap at i-1
                swap[i] = min(swap[i], noSwap[i-1]+1); //swap at i, no swap at i-1
            }
        }
        return min(swap.back(), noSwap.back());
    }
};
