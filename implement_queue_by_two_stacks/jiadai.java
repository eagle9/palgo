//jiadai c++  --> java, Your submission beats 99.40% Submissions!
//implement push and top first, then pop with top
public class MyQueue {
    private Stack<Integer> stack1 = new Stack<>();
    private Stack<Integer> stack2 = new Stack<>();

    MyQueue() {
        // do intialization if necessary
    }

    public void push(int element) {
        // write your code here
        stack1.push(element);
    }

    public int pop() {
        int result = top();
        stack2.pop();
        return result;
    }

    int top() {
        if (stack2.size() == 0) {
            while (!stack1.empty()) {
                stack2.push(stack1.pop());
            }
        }

        return stack2.peek();
    }
};
