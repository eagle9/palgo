//grandyang, using 1 stack, beats 22%
/*
只用到了一个栈，还需要一个整型变量min_val来记录当前最小值，初始化为整型最小值，然后如果需要进栈的数字小于等于当前最小值min_val，那么将min_val压入栈，并且将min_val更新为当前数字。在出栈操作时，先将栈顶元素移出栈，再判断该元素是否和min_val相等，相等的话我们将min_val更新为新栈顶元素，再将新栈顶元素移出栈即可，
*/
public class MinStack {
    private int min_val = Integer.MAX_VALUE;
    private Stack<Integer> s = new Stack<>();
    
    /** initialize your data structure here. */
    public MinStack() {}
    
    public void push(int x) {
        if (x <= min_val) {
            s.push(min_val);
            min_val = x;
        }
        s.push(x);
    }
    
    public void pop() {
        if (s.pop() == min_val) min_val = s.pop();
    }
    
    public int top() {
        return s.peek();
    }
    
    public int getMin() {
        return min_val;
    }
}

