/*
runtime 7ms, faster than 99%, mem less than 100%

use atomicInteger to count elements
use synchronized for mutex
http://n00tc0d3r.blogspot.com/2013/08/implement-bounded-blocking-queue.html?view=classic
*/
class BoundedBlockingQueue {
    private final int capacity;  
    private final Queue<Integer> queue = new LinkedList<Integer>(); 
    private final AtomicInteger count = new AtomicInteger(0); 
    
    public BoundedBlockingQueue(int capacity) {
        if (capacity <= 0)  throw new IllegalArgumentException("The capacity of the queue must be > 0.");
        this.capacity = capacity;  
    }
    
    public synchronized void enqueue(Integer element) throws InterruptedException {
        if (element == null) throw new NullPointerException("Null element is not allowed.");  
   
        int oldCount = -1;
        while (count.get() == capacity) wait();  
   
        queue.add(element);  
        oldCount = count.getAndIncrement();  
        if (oldCount == 0) {
            notifyAll(); // notify other waiting threads (could be producers or consumers)  
        }
    }
    
    public synchronized int dequeue() throws InterruptedException {
        Integer e;  
   
        int oldCount = -1;
        while (count.get() == 0) wait();  
  
        e = queue.remove();  
        oldCount = count.getAndDecrement();  
        if (oldCount == this.capacity) {
            notifyAll(); // notify other waiting threads (could be producers or consumers)  
        }
        return e;
    }
    
    public int size() {  
        return count.get();  
    }  
}

