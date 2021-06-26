////zhengyang permutation index ii, also works with permutation index
//modified for easier understanding
//Your submission beats 93.60% Submissions!
//advantage of this program is that it works for both permutation index and ii
public class Solution {
    /**
     * @param A an integer array
     * @return a long integer
     */
    public long permutationIndex(int[] A) {
        if(A == null || A.length == 0){
            return 0;
        }

        //use long because using int may be out bound
        long index = 1;//index start from 1
        long fact = 1;
        long factForReps = 1;
        //map stores repetition count of each number in A
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
        //iterate from tail of A
        for(int i = A.length - 1; i >= 0; i--){
            if(!map.containsKey(A[i])){
                map.put(A[i], 1);
            }else{
                map.put(A[i], map.get(A[i]) + 1);
                factForReps *= map.get(A[i]);
            }

            int countSmaller = 0;
            //j iterate from i+1 to tail
            //count how many numbers after A[i]
            for(int j = i + 1; j < A.length; j++){
                if(A[j] < A[i]){
                    countSmaller++;
                }
            }

            index += countSmaller * fact / factForReps;
            fact *= A.length - i;
        }

        return index;
    }
}
