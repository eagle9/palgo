/*shaun's original idea using two stacks, failed 1 case
//stack 1 for regular push pop top
//stack 2 to store the min elements so far, only push x <= s2.top 
//when s1 pop, check if top == s2.top()

//fixed and accepted, runtime 36ms, faster than 84%, mem less than 94%
compared to MaxStack, popMax is pretty hard to implement
minStack, no popMin, so easier
*/
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        s1.push(x);
        if (s2.empty() || x <= s2.top() ) s2.push(x);
        //if (s2.empty() || x < s2.top() ) s2.push(x); ===> runtime error
        //lintcode fails 1 case [1, 1, 1, 1]
    }
    
    void pop() {
        if (s1.empty()) return;
        int x = top(); s1.pop();
        if (x == s2.top()) s2.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }
private:
    stack<int> s1, s2;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
