//youtube defog tech and stackoverflow blocking queue implemenation
//use of lock and its condition await and signalAll(not notifyAll)
//initially i used notifyAll which led to IllegalMonitorState
//concurrent producer and consumer pattern with a bounded quque(thread safe)
//defog tech idea, shaun implemented and run okay after 1 bug fix
//approach 3, already tried allen downey's semaphore approach
import java.util.LinkedList;
import java.util.Queue;
import java.util.Random;
import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;
import java.util.concurrent.Semaphore;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

class ProducerConsumer {
	public static void main(String [] args){
		//approach1(); //run okay
		//approach2(); //run okay
		approach3();
	}
	
	private static void approach1() {
		BlockingQueue<Integer> queue = new ArrayBlockingQueue<>(10);
		/*
		 * 
		 * Runnable task1 = new Runnable(){
 
    		@Override
    		public void run(){
        		System.out.println("Task #1 is running");
    		}
		};
 		 */
		final Runnable producer = () -> {
			while(true) {
				Random rand = new Random();
				try {
					queue.put(rand.nextInt());
				} catch (InterruptedException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
		};
		new Thread(producer).start();
		new Thread(producer).start();

		//Consumer
		final Runnable consumer = () -> {
			while(true) {
				try {
					Integer i = queue.take();
					System.out.println("processing " + i);
				} catch (InterruptedException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				
			}
		};
		new Thread(consumer).start();
		new Thread(consumer).start();
		try {
			Thread.sleep(1000);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	
	
	private static void approach2() {
		MyBlockingQueue<Integer> queue = new MyBlockingQueue<>(10);
		//BQueue<Integer> queue = new BQueue<>();
		/*
		 * 
		 * Runnable task1 = new Runnable(){
 
    		@Override
    		public void run(){
        		System.out.println("Task #1 is running");
    		}
		};
 		 */
		final Runnable producer = () -> {
			while(true) {
				Random rand = new Random();
				queue.put(rand.nextInt());
			}
		};
		new Thread(producer).start();
		new Thread(producer).start();

		//Consumer
		final Runnable consumer = () -> {
			while(true) {
				Integer i = queue.take();
				System.out.println("processing " + i);
				
			}
		};
		new Thread(consumer).start();
		new Thread(consumer).start();
		try {
			Thread.sleep(1000);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	//allen downey using semaphore, run okay
	private static void approach3() {
		/*
		1 mutex = Semaphore(1)
		2 items = Semaphore(0)
		3 spaces = Semaphore(buffer.size())
		
		Listing 4.11: Finite buffer consumer solution
1 items.wait()
2 mutex.wait()
3 event = buffer.get()
4 mutex.signal()
5 spaces.signal()
6
7 event.process()

Listing 4.12: Finite buffer producer solution
1 event = waitForEvent()
2
3 spaces.wait()
4 mutex.wait()
5 buffer.add(event)
6 mutex.signal()
7 items.signal()
In order to avoid deadlock, producers and consumers check availability before
getting the mutex. For best performance, they release the mutex before
signaling.
		*/
		Queue<Integer> buffer = new LinkedList<>();
		int size = 10;
		
		//init 
		Semaphore mutex = new Semaphore(1);
		Semaphore items = new Semaphore(0);
		Semaphore spaces= new Semaphore(size);
		Random rand = new Random();
		
		final Runnable consumer = () -> {
			try {
				while (true) {
					items.acquire();
					mutex.acquire();
					Integer i = buffer.poll();
					System.out.println("consuming " + i);
					mutex.release();
					spaces.release();
				}
				
			} catch (InterruptedException e) {
				
			}
			
		};
		new Thread(consumer).start();
		new Thread(consumer).start();
		final Runnable producer = () -> {
			
			try {
				while (true) {
					spaces.acquire();
					mutex.acquire();
					int i = rand.nextInt();
					buffer.offer(i);
					System.out.println("producing " + i);
					mutex.release();
					items.release();
				}
			} catch (InterruptedException e) {}
				
			
		};
		new Thread(producer).start();
		new Thread(producer).start();
		
	}

}

class BQueue<T> {
	private Condition isFullCondition;
	private Condition isEmptyCondition;
	private Lock lock;
	
	private Queue<T> q = new LinkedList<T>();
    private int limit;
    
	public BQueue() {
	    this(Integer.MAX_VALUE);
	}
	
	public BQueue(int limit) {
	    this.limit = limit;
	    lock = new ReentrantLock();
	    isFullCondition = lock.newCondition();
	    isEmptyCondition = lock.newCondition();
	}
	
	public void put (T t) {
	    lock.lock();
	    try {
	       while (q.size() == limit) {
	            try {
	                isFullCondition.await();
	            } catch (InterruptedException ex) {}
	        }
	        q.add(t);
	        isEmptyCondition.signalAll();
	    } finally {
	        lock.unlock();
	    }
	 }
	
	
	public T take() {
	    T t = null;
	    lock.lock();
	    try {
	        while (q.isEmpty()) {
	            try {
	                isEmptyCondition.await();
	            } catch (InterruptedException ex) {}
	        }
	        t = q.poll();
	        isFullCondition.signalAll();
	    } finally { 
	        lock.unlock();
	    }
	    return t;
	}
	
		
}

class MyBlockingQueue<E>{
	private Queue<E> queue;
	private int max;
	private ReentrantLock lock ;
	private Condition isFull;
	private Condition isEmpty;
	
	MyBlockingQueue(int size) {
		queue = new LinkedList<E>(); 
		this.max = size;
		
		lock = new ReentrantLock();
		isFull = lock.newCondition();
		isEmpty = lock.newCondition();
		
		
	}
	public void put(E i) {
		lock.lock();
		try {
			while (queue.size() == max) {
				try {
					isFull.await();
				} catch (InterruptedException e) {}
			}
			queue.offer(i);
			//isEmpty.notifyAll(); //bug
			isEmpty.signalAll();
		} 
		finally {
			lock.unlock();
		}
	}
	public E take( ) {
		lock.lock();
		E i = null;
		try {
			while (queue.isEmpty()) {
				try {
					isEmpty.await();
				} catch (InterruptedException e) {}
			}
			i = queue.poll();
			//isFull.notifyAll();
			isFull.signalAll();

		} finally {
			lock.unlock();
		}
		return i;
		
	}

}

