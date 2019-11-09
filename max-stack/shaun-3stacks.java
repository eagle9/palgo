//shaun coded in java, 3 stack idea
//runtime 80ms, faster than 58%, mem less than 8%
class MaxStack {
    private Stack<Integer> s1, s2;
    /** initialize your data structure here. */
    public MaxStack() {
        s1 = new Stack<>();
        s2 = new Stack<>();
    }
    
    public void push(int x) {
        s1.push(x);
        if (s2.isEmpty() || x >= s2.peek()) s2.push(x);
    }
    
    public int pop() {
        int t = s1.pop();
        if (t == s2.peek()) s2.pop();
        return t;
    }
    
    public int top() {
        return s1.peek();
    }
    
    public int peekMax() {
        return s2.peek();
    }
    
    public int popMax() {
        int mx = s2.pop();
        Stack<Integer> temp = new Stack<>();
        while (s1.peek() != mx) {
            int x = s1.pop();
            temp.push(x);
        }
        //now s1.peek == mx
        s1.pop();
        //push all elements in temp back to stack
        while (!temp.isEmpty()) {
            push(temp.pop());
        }
        return mx;
    }
}

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack obj = new MaxStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.peekMax();
 * int param_5 = obj.popMax();
 */
