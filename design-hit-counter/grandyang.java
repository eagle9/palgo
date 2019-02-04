//grandyang idea, shaun java code, runtime 61ms, faster than 33%
class HitCounter {

    /** Initialize your data structure here. */
    public HitCounter() {
        queue = new LinkedList<>();
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    public void hit(int timestamp) {
        //hit will be called with timestamp in increasing order
        queue.offer(timestamp);
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    public int getHits(int timestamp) {
        //head of queue too early/old
        //while (queue.peek() < timestamp - 300) queue.poll();
        //while (!queue.isEmpty() && queue.peek() < timestamp - 300)
        //from the example, 1 is not included when the timestamp is 301, so <= for poll
        while (!queue.isEmpty() && queue.peek() <= timestamp - 300)
            queue.poll();
        
        return queue.size();
    }
    private Queue<Integer> queue = null;
}

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */
