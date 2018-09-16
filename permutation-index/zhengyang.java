//zhengyang, Your submission beats 96.80% Submissions!
public class Solution {
    /**
     * @param A an integer array
     * @return a long integer
     */
    public long permutationIndex(int[] A) {
        // Write your code here
        if(A == null || A.length == 0){
            return 0;
        }

        int n = A.length;
        //in order to avoid changing A's element order, make a copy
        int[] array = Arrays.copyOf(A, n);
        Arrays.sort(array);
        //store the number of elements that are less than current element to map
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
        for(int i = 0; i < n; i++){
            map.put(array[i], i); //array is sorted, number of numbers that before array[i]
        }

        //index start from 1
        long sum = 1;
        for(int i = 0; i < n; i++){
            //
            sum += map.get(A[i]) * factor(n - 1 - i);
            updateMap(map, A[i]); //why???
        }

        return sum;
    }

    private long factor(int n){ //factorial
        long now = 1;
        for(int i = 1; i <= n; i++){
            now *= (long) i;
        }
        return now;
    }

    private void updateMap(HashMap<Integer, Integer> map, int current){
        for(int key : map.keySet()){
            //update val for key > current, since current is taken and could not be used anymore, 
            //for more check README.md explanation
            if(key>current){
                int val = map.get(key);
                map.put(key, val - 1);
            }
        }
    }
}
