//yuanbin, Your submission beats 85.40% Submissions!
//https://algorithm.yuanbin.me/zh-hans/exhaustive_search/permutation_index.html
//this algorithm can be easily extended to deal with duplicate number in A, as in permutation index ii
//Time: O(n^2), Space: O(1)
public class Solution {
    /**
     * @param A an integer array
     * @return a long integer
     */
    public long permutationIndex(int[] A) {
        if (A == null || A.length == 0) return 0L;

        long index = 1, fact = 1;
        for (int i = A.length - 1; i >= 0; i--) {
            // count number that < A[i]
            int countSmaller = 0;
            for (int j = i + 1; j < A.length; j++) {
                if (A[j] < A[i]) countSmaller++;
            }

            index += countSmaller * fact;
            fact *= (A.length - i);
        }

        return index;
    }
}
