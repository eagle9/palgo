//runtime 4ms, faster than 100%, mem less than 100%
//https://juejin.im/post/5d350ca1f265da1b6a34d16c
//
import java.util.concurrent.*;
class ZeroEvenOdd {
    private int n, count;
    private Semaphore zero, even, odd, mutex;
    public ZeroEvenOdd(int n) {
        this.n = n;
        this.count = 1; //i to be printed
        this.zero = new Semaphore(1);
        this.even = new Semaphore(0);
        this.odd = new Semaphore(0);
        this.mutex = new Semaphore(1); //not needed
        //using 3 semaphores zero, even and odd, 3 threads can only execute 1 thread at a time
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void zero(IntConsumer printNumber) throws InterruptedException {
        while (true) {
            zero.acquire();
            if (count > n) break;
            
            printNumber.accept(0);
            
            
            //read and write i should be put into critical section
            //mutex.acquire();
            if (count % 2 == 1) {
                odd.release();
            }else {
                even.release();
            }
            //mutex.release();
        }
        
    }

    public void even(IntConsumer printNumber) throws InterruptedException {
        for (int i = 0; i < n/2; i++) {
            even.acquire();
            printNumber.accept(count++);
            zero.release();
        }
        
        /*
        //init try
        even.acquire();
        
        mutex.acquire();
        printNumber.accept(i);
        i++;
        mutex.release();
        
        zero.release(); // enable 0 print
        */
    }

    public void odd(IntConsumer printNumber) throws InterruptedException {
        for (int i = 0; i < n/2+n%2; i++) {
            odd.acquire();
            printNumber.accept(count++);
            zero.release();
        }
        /*odd.acquire();
        
        mutex.acquire();
        printNumber.accept(i);
        i++;
        mutex.release();
        
        zero.release();*/
    }
}
