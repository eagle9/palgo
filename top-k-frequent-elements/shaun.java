
/*
lt hash table and heap
shaun understood, feb 25 2019
same solution to top k frequent elements
Runtime: 16 ms, faster than 69.67% of Java online submissions for Top K Frequent Elements.
Memory Usage: 42.6 MB, less than 12.23% of Java online submissions for Top K Frequent Elements.
*/
class Solution {
    public int [] topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> count = new HashMap();
        for (int i: nums) {
            count.put(i, count.getOrDefault(i, 0) + 1);
        }
        
        
        Comparator<Integer> cmp = new Comparator<Integer>() {
            public int compare(Integer a, Integer b) {
                int count1 = count.getOrDefault(a,0);
                int count2 = count.getOrDefault(b,0);
                //smaller count at top
                if (count1 != count2) return count1 - count2;
                //same count, greater number at top, z word will be removed
                return b.compareTo(a);
                
            }
        };
        PriorityQueue<Integer> minHeap = new PriorityQueue<Integer>((a,b) ->{
            int count1 = count.getOrDefault(a,0);
            int count2 = count.getOrDefault(b,0);
            //smaller count at top
            if (count1 != count2) return count1 - count2;
                //same count, greater number at top, z word will be removed
            return b.compareTo(a);
        });
       
	   	//use minHeap, only keep <=k elements, min elements will be off the top	
        for (Integer i: count.keySet()) {
            minHeap.offer(i);
            if (minHeap.size() > k) minHeap.poll();
        }
        
        int len = minHeap.size();
        int [] ans = new int[len];
        int i = len -1;
        while (!minHeap.isEmpty()) {
            ans[i--] = minHeap.poll();
        }
        
        return ans;
    }
}


