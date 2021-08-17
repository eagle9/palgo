//https://blog.csdn.net/MrJustin/article/details/105744037
class ExamRoom {
    PriorityQueue<Interval> pq;
    int N;

    public ExamRoom(int N) {
        //max length interval
        this.pq = new PriorityQueue<>((a, b) -> a.dist != b.dist? b.dist - a.dist : a.x - b.x);
        this.N = N;
        pq.add(new Interval(-1, N));
    }

    // O(logn): poll top candidate, split into two new intervals
    public int seat() {
        int seat = 0;
        Interval interval = pq.poll();
        if (interval.x == -1) seat = 0;
        else if (interval.y == N) seat = N - 1;
        else seat = (interval.x + interval.y) / 2; 
        
        //split
        pq.offer(new Interval(interval.x, seat));
        pq.offer(new Interval(seat, interval.y));
            
        return seat;
    }
    
    // O(n)Find head and tail based on p. Delete and merge two ends
    public void leave(int p) {
        Interval head = null, tail = null;
       
        //   head.x----     p ---tai.y
        for (Interval interval : pq) {
            if (interval.x == p) tail = interval;
            if (interval.y == p) head = interval;
            if (head != null && tail != null) break;
        }
        // Delete
        pq.remove(head);
        pq.remove(tail);
        // Merge
        pq.offer(new Interval(head.x, tail.y));
    }
    
    class Interval {
        int x, y, dist;
        public Interval(int x, int y) {
            this.x = x;
            this.y = y;
            if (x == -1) {
                this.dist = y;
            } else if (y == N) {
                this.dist = N - 1 - x;
            } else {
                //why half???
                this.dist = Math.abs(x - y) / 2;    
            }
        }
    }
}

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom obj = new ExamRoom(n);
 * int param_1 = obj.seat();
 * obj.leave(p);
 */
