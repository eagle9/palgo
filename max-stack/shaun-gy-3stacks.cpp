//grandyang idea with 2 stacks
//use stack2 to store the max, push to s2 only when x >= s2.top
//runtime 92ms, faster than 79%, mem less than 35%
class MaxStack {
public:
    /** initialize your data structure here. */
    MaxStack() {}
    
    void push(int x) {
        if (s2.empty() || x >= s2.top()) s2.push(x);
        s1.push(x);
    }
    
    int pop() {
        int t = s1.top(); s1.pop();
        if (!s2.empty() && s2.top() == t) s2.pop();
        
        return t;
    }
    
    int top() {
        return s1.top();
    }
    
    int peekMax() {
        return s2.top();
    }
    
    int popMax() {
        int mx = s2.top();
        
        //remove mx from s1
        stack<int> t;
        while (s1.top() != s2.top()) {
            t.push(s1.top()); s1.pop();
        }
        //now s1.top == s2.top, remove them
        s1.pop(); s2.pop();
        
        //push elements in t back to max stack
        while (!t.empty()) {
            push(t.top()); t.pop();
        }
        
        return mx;
    }

private:
    stack<int> s1, s2;
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack obj = new MaxStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.peekMax();
 * int param_5 = obj.popMax();
 */
