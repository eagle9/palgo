//shaun's own idea and code with semaphore
//accepted first sub, 
//runtime 16ms, faster than 80%, mem less than 100%
import java.util.concurrent.*;
class FooBar {
    private int n;
    private Semaphore sem1, sem2;
    public FooBar(int n) {
        this.n = n;
        this.sem1 = new Semaphore(1); //control print foo
        this.sem2 = new Semaphore(0); //control print bar
    }

    public void foo(Runnable printFoo) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
            sem1.acquire();
        	// printFoo.run() outputs "foo". Do not change or remove this line.
        	printFoo.run();
            sem2.release();
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
            sem2.acquire();
            // printBar.run() outputs "bar". Do not change or remove this line.
        	printBar.run();
            sem1.release();
        }
    }
}
