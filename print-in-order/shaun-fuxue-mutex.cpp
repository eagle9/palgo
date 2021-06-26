//https://blog.csdn.net/fuxuemingzhu/article/details/95889253
/*
一般情况下，最简单的协调不同线程之间的调度关系，都可以使用mutex来做，本质是信号量。

std::mutex 的成员函数有四个：

构造函数，std::mutex不允许拷贝构造，也不允许 move 拷贝，最初产生的 mutex 对象是处于 unlocked 状态的。
lock()，调用线程将锁住该互斥量。线程调用该函数会发生下面 3 种情况：
(1). 如果该互斥量当前没有被锁住，则调用线程将该互斥量锁住，直到调用 unlock之前，该线程一直拥有该锁。
(2). 如果当前互斥量被其他线程锁住，则当前的调用线程被阻塞住。
(3). 如果当前互斥量被当前调用线程锁住，则会产生死锁(deadlock)。
unlock()， 解锁，释放对互斥量的所有权。
try_lock()，尝试锁住互斥量，如果互斥量被其他线程占有，则当前线程也不会被阻塞。线程调用该函数也会出现下面 3 种情况，
(1). 如果当前互斥量没有被其他线程占有，则该线程锁住互斥量，直到该线程调用 unlock 释放互斥量。
(2). 如果当前互斥量被其他线程锁住，则当前调用线程返回 false，而并不会被阻塞掉。
(3). 如果当前互斥量被当前调用线程锁住，则会产生死锁(deadlock)。
也就是说一个锁能控制两个线程的执行顺序。这个题中我们需要保持三个函数是按顺序执行的，则需要两个锁m1和m2。

在开始的时候，两个锁都锁起来。first()可以直接执行，second()等待m1释放之后执行，third()等待m2释放之后执行。first()结束之后释放m1，second()结束之后释放m2.因此三个的顺序都协调一致了。

shaun: mutex lock() ---> acquire,   unlock ---> release, mutex resource count == 1
runtime 140ms, faster than 75%, mem less than 100%
*/
class Foo {
private:
    mutex m1, m2;
public:
    Foo() {
        m1.lock();
        m2.lock();
    }

    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        m1.unlock();
    }

    void second(function<void()> printSecond) {
        m1.lock();
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        m1.unlock();
        m2.unlock();
    }

    
    void third(function<void()> printThird) {
        m2.lock();
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        m2.unlock();
    }
};

void printFirst() {
    cout << "first";
}

void printSecond() {
    cout << "second";
}

void printThird() {
    cout << "third";
}

