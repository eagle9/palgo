class FizzBuzz {
    private int n;
    private static final Object LOCK = new Object();
    private static int CURRENT;
    
    public FizzBuzz(int n) {
        this.n = n;
        CURRENT = 1;
    }

    public void fizz(Runnable printFizz) throws InterruptedException {
        synchronized (LOCK) {
            while (CURRENT <= n) {
                if (CURRENT % 3 == 0 && CURRENT % 5 != 0) {
                    printFizz.run();
                    CURRENT++;
                    LOCK.notifyAll();
                } else {
                    LOCK.wait();
                }
            }
        }
    }

    public void buzz(Runnable printBuzz) throws InterruptedException {
        synchronized (LOCK) {
            while (CURRENT <= n) {
                if (CURRENT % 5 == 0 && CURRENT % 3 != 0) {
                    printBuzz.run();
                    CURRENT++;
                    LOCK.notifyAll();
                } else {
                    LOCK.wait();
                }
            }
        }
    }

    public void fizzbuzz(Runnable printFizzBuzz) throws InterruptedException {
        synchronized (LOCK) {
            while (CURRENT <= n) {
                if (CURRENT % 3 == 0 && CURRENT % 5 == 0) {
                    printFizzBuzz.run();
                    CURRENT++;
                    LOCK.notifyAll();
                } else {
                    LOCK.wait();
                }
            }
        }
    }

    public void number(IntConsumer printNumber) throws InterruptedException {
        synchronized (LOCK) {
            while (CURRENT <= n) {
                if (CURRENT % 3 != 0 && CURRENT % 5 != 0) {
                    printNumber.accept(CURRENT);
                    CURRENT++;
                    LOCK.notifyAll();
                } else {
                    LOCK.wait();
                }
            }
        }
    }
}
