//grandyang idea1, shaun java code, beats 74%
class Solution {
    class Pair {
        int first;
        int second;
        public Pair(int first, int second) {
            this.first = first;
            this.second= second;
        }
    }
    
    public List<Integer> topKFrequent(int[] nums, int k) {
        Map<Integer,Integer> m = new HashMap<>();
        //key point: use a max heap, order by count/frequency
        PriorityQueue<Pair> q = new PriorityQueue<>(new Comparator<Pair>(){
            public int compare(Pair a, Pair b) {
                return b.first - a.first;
            }
        });
        List<Integer> res = new ArrayList<>();
        //couting number frequency
        for (int i = 0; i < nums.length; i++) {
            if (!m.containsKey(nums[i])) {
                m.put(nums[i], 1);
            }else {
                m.put(nums[i], m.get(nums[i]) + 1);
            }
        }
        //add pair<count,number> to max heap
        for (Integer n: m.keySet()) {
            Integer count = m.get(n);
            q.offer(new Pair(count,n));
        }
        //take top k from heap
        for (int i =0; i < k; i++) {
            Pair p = q.poll();
            res.add(p.second);
        }
        return res;
    }
}

