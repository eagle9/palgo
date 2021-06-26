//shaun's own code, beats 24%
//https://www.quora.com/What-is-the-difference-between-queue-and-deque
class RecentCounter {
    //Queue<Integer> queue;  //beats 24%
    Deque<Integer> queue;   //deque interface beats 57%
    public RecentCounter() {
        queue = new LinkedList<>();
        queue = new ArrayList<>();
    }
    
    //t in ms timestamp
    public int ping(int t) {
        //remove all timestamps that have expired
        while (!queue.isEmpty() && t - queue.peek() > 3000 ) {
            queue.poll();
        }
        queue.offer(t);
        return queue.size();
    }
}

//fishercode beats 64%
class RecentCounter {



    Deque<Integer> deque;

    public RecentCounter() {
        deque = new LinkedList<>();
    }

    public int ping(int t) {
        while (!deque.isEmpty() && t - deque.getFirst() > 3000) {
            deque.removeFirst();
        }
        deque.addLast(t);
        return deque.size();
    }
        
}


