/*
lt discuss idea, shaun read and understood, modified, all use Semaphore
runtime 7ms, faster than 99%, mem less than 100%
*/
class BoundedBlockingQueue {
        // addLast[============>removeFirst
        Deque<Integer> que = new LinkedList<>();

        // prevents consummers from reading elements when the queue does not have elements
        Semaphore items = new Semaphore(0); //for dequeue, how many items to take, init with 0
		Semaphore mutex = new Semaphore(1); //mutex used to control access to que
		// prevents producers from adding elements when the queue is full
        Semaphore cells = null; //how many empty cells where we can put into items
        
        public BoundedBlockingQueue(int capacity) {
            cells = new Semaphore(capacity); //start with cap empty cells
        }
        
        public void enqueue(int element) throws InterruptedException {
            cells.acquire(); //need 1 empty cell for putting a item
            /*synchronized (que) {
                que.addLast(element);                
            }*/
            mutex.acquire();
            que.addLast(element);
            mutex.release();
            
            items.release(); //items put, increase items
        }
        
        public int dequeue() throws InterruptedException {
            items.acquire(); //need 1 item to take away
            int res = -1;
            /*synchronized (que) {
                res = que.removeFirst();
            }*/
            mutex.acquire();
            res = que.removeFirst();
            mutex.release();
            
            cells.release(); // removed, one more empty cells, inc cells semaphore
            return res;
        }
        
        public int size() {
            return que.size(); //works
            //return empty.availablePermits();
        }
    }
