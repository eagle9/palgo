// base on heap
//use minheap, add the numbers one by one to the pq, only keep k numbers in the pq. 
//in other word, once the size of pq > k, poll the number out. 
//the head of the pq stores the smallest number. at last the numbers in the pq will be top k largest. 
//jz beats 73%
//heap insert time complexity is O(logn), peek is O(1), offer/poll time is O(logn)
//so the time for the solution is n*logk, extra space is O(k)
class Solution {
    /*
     * @param nums an integer array
     * @param k an integer
     * @return the top k largest numbers in array
     */
     public int[] topk(int[] nums, int k) {
         /*
         PriorityQueue<Integer> minheap = new PriorityQueue<Integer>(k, new Comparator<Integer>() {
             public int compare(Integer o1, Integer o2) {
                 return o1 - o2;
             }
         }); */
         
         PriorityQueue<Integer> minheap = new PriorityQueue<>(k, new Comparator<Integer>() {
             public int compare(Integer o1, Integer o2) {
                 return o1 - o2;
             }
        }); //using integer natural ordering
        
        for (int i : nums) {
            minheap.add(i);
            if (minheap.size() > k) {
                minheap.poll();
            }
        }
        
        int [] result = new int[k];
        for (int i = k -1; i >=0; i--) {
            result[i] = minheap.poll();
        }
        return result;
        
        /*
        for (int i : nums) {
             minheap.add(i);
             if (minheap.size() > k) {
                minheap.poll();
             }
         }

         int[] result = new int[k];
         for (int i = 0; i < result.length; i++) {
             result[k - i - 1] = minheap.poll();
         }
         return result; */
    }
};
