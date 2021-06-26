//beats 2%    
public class MaxStack {
      /**This is O(n) for popMax() and pop() while O(1) for the other three operations which is UN-acceptable during an interview!
       * We need to do better than O(n) time complexity in order to ace the interview!
       * But O(1) is impossible, so let's aim for O(logn).*/
        

            private int max;
            private Stack<Integer> stack;

            /**
             * initialize your data structure here.
             */
            public MaxStack() {
                max = Integer.MIN_VALUE;
                stack = new Stack<>();
            }

            public void push(int x) {
                if (x > max) {
                    max = x;
                }
                stack.push(x);
            }

            public int pop() {
                if (stack.peek() == max) {
                    int result = stack.pop();
                    max = findMax();
                    return result;
                } else {
                    return stack.pop();
                }
            }

            private int findMax() {
                if (!stack.isEmpty()) {
                    Iterator<Integer> iterator = stack.iterator();
                    int max = stack.peek();
                    while (iterator.hasNext()) {
                        max = Math.max(max, iterator.next());
                    }
                    return max;
                } else {
                    max = Integer.MIN_VALUE;
                    return max;
                }
            }

            public int top() {
                return stack.peek();
            }

            public int peekMax() {
                return max;
            }

            public int popMax() {
                Stack<Integer> tmp = new Stack<>();
                int result = 0;
                while (!stack.isEmpty()) {
                    if (stack.peek() != max) {
                        tmp.push(stack.pop());
                    } else {
                        result = stack.pop();
                        break;
                    }
                }
                while (!tmp.isEmpty()) {
                    stack.push(tmp.pop());
                }
                max = findMax();
                return result;
            }
        }
    


//grandyang c++ to java translate, runtime error
class MaxStack1 {
    private Stack<Integer> s1 = new Stack<>();
    private Stack<Integer> s2 = new Stack<>();
    
    /** initialize your data structure here. */
    public MaxStack1() {
        
    }
    
    public void push(int x) {
        //s2 used to store the max copy
        if (s2.empty() || s2.peek() <= x) s2.push(x);
        s1.push(x);
    }
    
    public int pop() {
        if (!s2.isEmpty() && s2.peek() == s1.peek()) s2.pop();
        if (s1.empty()) return -1;
        int t = s1.pop();
        return t;
    }
    
    public int top() {
        return s1.peek();
    }
    
    public int peekMax() {
        return s2.peek();
    }
    
    public int popMax() {
        if (s2.empty()) return -1;
        int mx = s2.peek();
        Stack<Integer> t = new Stack<>();
        while (s1.peek() != s2.peek()) {
            t.push(s1.pop()); 
        }
        s1.pop(); s2.pop();
        while (!t.empty()) {
            push(t.pop());
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
