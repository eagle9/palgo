class QueueNode {
    public int val;
    public QueueNode next;
    public QueueNode(int value) {
        val = value;
    }
}

public class Queue {

    private QueueNode dummy, tail;

    public Queue() {
        dummy = new QueueNode(-1);
        tail = dummy;
    }

    public void enqueue(int val) {
        QueueNode node = new QueueNode(val);
        tail.next = node;
        tail = node;
    }

    public int dequeue() {
        int ele = dummy.next.val;
        dummy.next = dummy.next.next;

        if (dummy.next == null) {
            tail = dummy;// reset
        }
        return ele;
    }

    public int peek() {
        int ele = dummy.next.val;
        return ele;
    }

    public boolean isEmpty() {
        return dummy.next == null;
    }
}
