//jiadai c++  --> java, Your submission beats 97.48% Submissions!
//key is to use 2 stacks, using stack 2 to reverse all elements in stack1
public class MyQueue {
    private Stack<Integer> stack1 = new Stack<>();
    private Stack<Integer> stack2 = new Stack<>();

    // ----------
    // st1   1 2 3
    //-----------
    // st2   3 2 1 
    //-----------
    MyQueue() {
        // do intialization if necessary
    }

    public void push(int element) {
        // write your code here
        stack1.push(element);
    }
    public int pop() {
        peek();
        return stack2.pop();
    }
    //get the head without remove it
    public int peek() {
        //if stack2 is empty, move all elements from stack1 to stack2
        //reverse all elments in stack1 into stack2
        if (stack2.size() == 0) {
            while (!stack1.empty()) {
                stack2.push(stack1.pop());
            }
        }

        return stack2.peek();
    }
    public boolean empty() {
        return stack1.isEmpty() && stack2.isEmpty();
    }
};
