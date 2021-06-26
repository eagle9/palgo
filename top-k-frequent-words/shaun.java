/*
lt hash table and heap
shaun understood, feb 25 2019
Runtime: 9 ms, faster than 99.92% of Java online submissions for Top K Frequent Words.
Memory Usage: 40.2 MB, less than 53.26% of Java online submissions for Top K Frequent Words.
*/
class Solution {
    public List<String> topKFrequent(String[] words, int k) {
        Map<String, Integer> count = new HashMap();
        for (String word: words) {
            count.put(word, count.getOrDefault(word, 0) + 1);
        }
        
        Comparator<String> cmp = new Comparator<String>() {
            public int compare(String a, String b) {
                int count1 = count.getOrDefault(a,0);
                int count2 = count.getOrDefault(b,0);
                //smaller count at top
                if (count1 != count2) return count1 - count2;
                //same count, greater word at top, z word will be removed
                return b.compareTo(a);
                
            }
        };
        PriorityQueue<String> minHeap = new PriorityQueue<String>(cmp);
        
        /*PriorityQueue<String> heap = new PriorityQueue<String>(
                (w1, w2) -> count.get(w1).equals(count.get(w2)) ?
                w2.compareTo(w1) : count.get(w1) - count.get(w2) );
        */
        for (String word: count.keySet()) {
            minHeap.offer(word);
            if (minHeap.size() > k) minHeap.poll();
        }

        List<String> ans = new ArrayList();
        while (!minHeap.isEmpty()) ans.add(minHeap.poll());
        Collections.reverse(ans);
        return ans;
    }
}
