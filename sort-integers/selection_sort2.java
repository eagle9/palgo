//selection sort v2, Your submission beats 78.00% Submissions!
public class Solution {
    /*
     * @param A: an integer array
     * @return: 
     */
    public void sortIntegers(int[] A) {
        for (int i = 0; i < A.length; i++) {
            //i    j=i+1 to n
            // if aj < ai, swap, so the min from i+1 to n will be put at ai
            for (int j = i + 1; j < A.length; j++) {
                if (A[j] < A[i]) {
                    int tmp = A[i];
                    A[i] = A[j];
                    A[j] = tmp;
                }
            }
        }
    }
}

