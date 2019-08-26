import java.util.concurrent.*;
import java.util.concurrent.locks.*;
/*
shaun's own idea with semaphore and lock(mutex)
accepted after 1 bug fix
first try use both semaphore and ReentrantLock
second try use only semaphore and count
check yangxu's, only semaphore, no count
but harder to understand

runtime 11ms, faster than 99.78%, mem less than 100%

*/
class H2O {
    private Semaphore sem1, sem2;
    private int count1, count2;
    private ReentrantLock lock;
    private Semaphore mutex;
    public H2O() {
        sem1= new Semaphore(2);
        sem2 = new Semaphore(1);
        lock = new ReentrantLock();
        mutex = new Semaphore(1);
    }

    public void hydrogen(Runnable releaseHydrogen) throws InterruptedException {
		sem1.acquire();
        // releaseHydrogen.run() outputs "H". Do not change or remove this line.
        releaseHydrogen.run();
        //lock.lock();
        mutex.acquire();
        count1++;
        if (count1 == 2 && count2 == 1) {
            //sem1.release();
            //sem1.release();
            sem1.release(2); //instead of release twice
            sem2.release();
            count1 = 0; //bug 1, remember to reset count1 and count2 to 0
            count2 = 0;
        }
        //lock.unlock();
        mutex.release();
    }

    public void oxygen(Runnable releaseOxygen) throws InterruptedException {
        sem2.acquire();
        // releaseOxygen.run() outputs "O". Do not change or remove this line.
		releaseOxygen.run();
        //lock.lock();
        mutex.acquire();
        count2++;
        if (count1 == 2 && count2 == 1) {
            sem1.release();
            sem1.release();
            sem2.release();
            count1 = 0;
            count2 = 0;
        }
        //lock.unlock();
        mutex.release();
    }
}
