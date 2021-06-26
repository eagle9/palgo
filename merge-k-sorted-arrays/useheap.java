//use heap or pq, beats 90.20%
//time is N(logN), kind of heapsort, which does not overcome the challenge
//modified from zhengyang, no good
public class Solution {
    /**
     * @param arrays: k sorted integer arrays
     * @return: a sorted array
     */
    public int[] mergekSortedArrays(int[][] arrays) {
        
        int n = 0;
        for (int i = 0; i < arrays.length; i++) {
            n += arrays[i].length;
        }
        PriorityQueue<Integer> queue = new PriorityQueue<Integer>();
        for(int i = 0; i < arrays.length; i++){
            for(int j = 0; j < arrays[i].length; j++){
                //queue.add(arrays[i][j]); //both .add .offer work
                queue.offer(arrays[i][j]);
            }
        }
        int k = 0;
        int [] merge = new int[n];
        
        while(!queue.isEmpty()){
            merge[k++] = queue.poll();
        }
        return merge;
    }
}
