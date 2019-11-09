/*
shaun imple of lightwindy idea of using array
dequeue from front,  enqueue from rear
simple idea, but details to avoid bug
runtime 32ms, faster than 82%, mem less than 91%

*/
class MyCircularQueue {
private:
    vector<int> data;
    int front =-1,rear = -1, len =0, cnt=0;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        data.resize(k);
        front = 0;
        rear = k-1;
        len = 0;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull()) return false;
        rear = (rear + 1) % data.size();
        data[rear] = value;
        len++;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty()) return false;
        front = (front + 1) % data.size();
        len--;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        return isEmpty()? -1: data[front];  //first time bug, isEmpty?
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        return isEmpty()? -1: data[rear];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return len == 0;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return len == data.size();
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
