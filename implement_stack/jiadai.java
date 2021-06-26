//jiadai c++ --> java, Your submission beats 66.40% Submissions!
// use linked list to implement Stack is very good, better than a list
public class Stack {
    private class Node {
        int val;
        Node next;
        Node(int v) {
            val = v;
            next = null;
        }
    };
    private Node head = null;
    /* * @param x: An integer
     * @return: nothing */
    public void push(int x) {
        // write your code here
        Node node = new Node(x);
        node.next = head;
        head = node;
    }

    /* * @return: nothing */
    public void pop() {
        Node node = head;
        head = head.next;
    }

    /* * @return: An integer */
    public int top() {
        return head.val;
    }

    /* * @return: True if the stack is empty */
    public boolean isEmpty() {
        return head == null;
    }

};
