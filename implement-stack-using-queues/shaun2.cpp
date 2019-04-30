//shaun 2nd round try, original idea and thinking on the fly, accepted after fixing some typos
//runtime 4ms, faster than 100%, mem less than 22%
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q1.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        //what if empty?  problem assume not empty, good question to ask
        int res = top();
        q1.pop();
        //q1 is now empty
        while (!q2.empty()) {
            int x = q2.front(); q2.pop();
            q1.push(x);
        }
        return res;
    }
    
    /** Get the top element. */
    int top() {
        while (q1.size() > 1) {
            int x = q1.front(); q1.pop();
            q2.push(x);
        }
        //now q1.size == 1
        return q1.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty() && q2.empty();
    }
private:
    queue<int> q1, q2;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
