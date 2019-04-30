//shaun 2nd try, original idea, thinking and code, 
//accepted first sub, runtime 4ms, faster than 100%, mem less than 33%
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int res = peek();
        s1.pop();
        //s1 empty now
        while (!s2.empty()) {
            int x = s2.top(); s2.pop();
            s1.push(x);
        }
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        while (s1.size() > 1) {
            int x = s1.top(); s1.pop();
            s2.push(x);
        }
        //now s1.size == 1
        return s1.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty() && s2.empty();
    }
private:
    stack<int> s1, s2;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
