//shaun's own code, with picture drawing and jiadai idea
//beats 80%, different signature from lintcode, with 2 queues
class MyStack {

    /** Initialize your data structure here. */
    public MyStack() {
        
    }
    
    private Queue<Integer> q1 = new LinkedList<>(); //main queue to accept push and track last element
    private Queue<Integer> q2 = new LinkedList<>();
    /** Push element x onto stack. */
    public void push(int x) {
        q1.offer(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        int res = top();
        q1.poll();
        
        Queue<Integer> temp = null;
        temp = q1;
        q1 = q2;
        q2 = temp;
        
        return res;
    }
    
    /** Get the top element. */
    public int top() {
        while (q1.size()>1) {
            q2.offer(q1.poll());
        }
        return q1.peek();
    }
    
    /** Returns whether the stack is empty. */
    public boolean empty() {
        return q1.isEmpty() && q2.isEmpty();
    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * boolean param_4 = obj.empty();
 */
