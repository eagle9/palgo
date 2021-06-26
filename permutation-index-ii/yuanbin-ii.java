//yuanbin, Your submission beats 85.40% Submissions!
//https://algorithm.yuanbin.me/zh-hans/exhaustive_search/permutation_index.html
//this algorithm can be easily extended to deal with duplicate number in A, as in permutation index ii
//Time: O(n^2), Space: O(1)
public class Solution {
    /**
     * @param A an integer array
     * @return a long integer
     */
    public long permutationIndexII(int[] A) {
        if (A == null || A.length == 0) return 0L;

        long index = 1, fact = 1;
        long factForReps = 1;  //extended for ii
        Map<Integer,Integer> map = new HashMap<>(); //for ii
        for (int i = A.length - 1; i >= 0; i--) {
            if (map.containsKey(A[i])) {
                map.put(A[i], map.get(A[i]) + 1);
                factForReps *= map.get(A[i]);
            }else {
                map.put(A[i],1);
            }
            // count number that < A[i]
            int countSmaller = 0;
            for (int j = i + 1; j < A.length; j++) {
                if (A[j] < A[i]) countSmaller++;
            }

            index += countSmaller * fact/ factForReps; //  divided by factForReps for ii
            fact *= (A.length - i);
        }

        return index;
    }
}
