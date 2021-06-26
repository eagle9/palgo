//https://pobenliu.gitbooks.io/leetcode/Merge%20Sorted%20Array.html
//Your submission beats 99.20% Submissions!
//time = O(m + n)
//space = O(m+n) 
// space can be reduced to O(1) if A.length = m+n and put A&B into A
public class Solution {
    /**
     * @param A: sorted integer array A
     * @param B: sorted integer array B
     * @return: A new sorted integer array
     */
    public int[] mergeSortedArray(int[] A, int[] B) {
        if (A == null || A.length == 0 ||
            B == null || B.length == 0) {
            return null;        
        }
        int n = B.length, m = A.length;
        int [] C = new int[m+n];
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        // compare the elements in A and B from the tail, two pointers
        while (i >= 0 && j >= 0) {
            if (A[i] > B[j]) { //take bigger one
                C[k--] = A[i--];
            } else {
                C[k--] = B[j--];
            }
        }
        //exit i == -1 or j == -1
        //make sure all elements in B and A moved to C 
        while (j >= 0) {
            C[k--] = B[j--];
        }
        while (i >= 0) {
            C[k--] = A[i--];
        }
        return C;
    }
    
}
