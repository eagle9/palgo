//gy max heap idea, shaun understood
class Solution {
    public String reorganizeString(String s) {
        Map<Character,Integer> m = new HashMap<>();
        PriorityQueue<Pair> maxHeap = new PriorityQueue<>( (a,b) -> {
            return Integer.compare(b.count, a.count);
        });
        for (char c : s.toCharArray()) {
            int count = m.getOrDefault(c, 0);
            m.put(c, count+1);
        }
        for (Character c: m.keySet()) {
            int count = m.get(c);
            if (count > (s.length() + 1) / 2) return "";
            maxHeap.offer(new Pair(count, c));
        }
        
        StringBuilder res = new StringBuilder();
        while (maxHeap.size() >= 2) {
            Pair p1 = maxHeap.poll();
            Pair p2 = maxHeap.poll();
            res.append(p1.c);
            res.append(p2.c);
            if (--p1.count > 0) maxHeap.offer(p1);
            if (--p2.count > 0) maxHeap.offer(p2);
        }
        if (maxHeap.size() > 0) {
            res.append(maxHeap.peek().c);
        }
        return res.toString();
    }
    class Pair {
        int count;
        char c;
        public Pair(int count, char c) {
            this.count = count;
            this.c = c;
        }
    }
}

