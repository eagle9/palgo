//jiadai Your submission beats 57.60% Submissions!
//draw a picture, it is not hard to understand
public class Stack {
    private Queue<Integer> Q1 = new LinkedList<>(); //Q1 is the main man
    private Queue<Integer> Q2 = new LinkedList<>();  //Q2 is the assistant 
    // Push a new item into the stack
    void push(int x) {
        // Write your code here
        Q1.offer(x);
    }

    // Pop the top of the stack
    void pop() {
        // Write your code here
        top();
        Q1.poll();
        Queue<Integer> temp = Q2;
        Q2 = Q1;
        Q1 = temp;
    }
    // Return the top of the stack
    int top() {
        // pop elements from Q1 until Q1 only have 1 element , which is the last in
        //top element is the last element in
        while (Q1.size() > 1) {
            Q2.offer(Q1.poll());
        }

        return Q1.peek();
    }
    // Check the stack is empty or not.
    boolean isEmpty() {
        // Write your code here
        return Q1.isEmpty() && Q2.isEmpty();
    }
};
