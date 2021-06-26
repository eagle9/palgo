//https://blog.csdn.net/fuxuemingzhu/article/details/95889253
/*
C++11中的新特性，可以把promise和future当做是在不同线程之间传递值的方式。在某个线程中对promise中生产一个数据，可以在另外一个线程中从future中获取这个数据。

promise和future是绑定在一起的，可以调用promise::get_future()获取与其绑定的future。
future.wait()方法对当前的线程进行阻塞，等待与其绑定的promise调用set_value()方法。
future.get()方法对当前的线程进行阻塞，等待与其绑定的promise调用set_value()方法的返回值.

 p1.set ---> p1.get_future.wait   p2.set --->       p2.get_future.wait
first      second                             third 

runtime 108ms, faster than 96%, mem less than 100%
*/
class Foo {
    private:
        std::promise<void> p1;
        std::promise<void> p2;
    public:
        Foo() {
        }

        void first(function<void()> printFirst) {
            // printFirst() outputs "first". Do not change or remove this line.
            printFirst();
            p1.set_value();
        }

        void second(function<void()> printSecond) {
            p1.get_future().wait();
            // printSecond() outputs "second". Do not change or remove this line.
            printSecond();
            p2.set_value();
        }


        void third(function<void()> printThird) {
            p2.get_future().wait();
            // printThird() outputs "third". Do not change or remove this line.
            printThird();
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
