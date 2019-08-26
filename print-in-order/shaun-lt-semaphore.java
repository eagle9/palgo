//lt discuss using semaphore
//runtime 9ms, faster than 90%, mem less than 100%
import java.util.concurrent.Semaphore;

class Foo {
    Semaphore run2;
    Semaphore run3;

    public Foo() {
        run2 = new Semaphore(0); //init with 0, let t2 wait for its release, by t1
        run3 = new Semaphore(0); //init run3 with 0, let t3 wait for its release, by t2
    }

    public void first(Runnable printFirst) throws InterruptedException {
        printFirst.run();
        run2.release();
    }

    public void second(Runnable printSecond) throws InterruptedException {
        run2.acquire();
        printSecond.run();
        run3.release();
    }

    public void third(Runnable printThird) throws InterruptedException {
        run3.acquire();
        printThird.run();
    }
}
