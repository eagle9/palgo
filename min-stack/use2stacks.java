//using two stacks, beats 95%
class MinStack {
    //main stack
    Stack<Integer> stack = new Stack<>();
    //save copy of the min: prev min, min, ....
    Stack<Integer> min = new Stack<>();
    
    public void push(int x) {
        stack.push(x);
        //save x to min stack? 
        if (min.isEmpty() || x <= getMin()) {
            min.push(x);
        }
    }

    public void pop() {
        int x = stack.pop();
        //if x is the min, remove it from min
        if (x == getMin()) {
            min.pop();
        }
        
    }

    public int top() {
        return stack.peek();
    }

    public int getMin() {
        return min.peek();
    }
}

