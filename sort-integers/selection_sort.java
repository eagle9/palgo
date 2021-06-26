//selection sort, Your submission beats 85.20% Submissions!
public class Solution {
    /*
     * @param A: an integer array
     * @return: 
     */
    public void sortIntegers(int[] A) {
        // write your code here
        for (int i = 0; i < A.length; i++) {
            int minIdx = i;  //minIdx from i to n-1
            for (int j = i; j < A.length; j++) {
				//update minIdx
                if (A[j] < A[minIdx]) {
                    minIdx = j;
                }
            }
			//minIdx <-> i, i from 0 to n-1
            int tmp = A[i];
            A[i] = A[minIdx];
            A[minIdx] = tmp;
        }
    }
}
