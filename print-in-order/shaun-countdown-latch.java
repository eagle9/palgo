import java.util.concurrent.CountDownLatch;
//https://github.com/RodneyShag/LeetCode_solutions/blob/master/Solutions/Print%20in%20Order.md
//runtime 10ms, faster than 89%, mem less than 100%
class Foo {
    private final CountDownLatch latch2;
    private final CountDownLatch latch3;

    public Foo() {
        latch2 = new CountDownLatch(1);
        latch3 = new CountDownLatch(1);
    }

    public void first(Runnable printFirst) throws InterruptedException {
        printFirst.run();
        latch2.countDown();
    }

    public void second(Runnable printSecond) throws InterruptedException {
        latch2.await();
        printSecond.run();
        latch3.countDown();
    }

    public void third(Runnable printThird) throws InterruptedException {
        latch3.await();
        printThird.run();
    }
}
/*
Time/Space Complexity
Time Complexity: O(1)
Space Complexity: O(1)
*/
