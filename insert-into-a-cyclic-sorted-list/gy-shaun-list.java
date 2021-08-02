package org.voyiger.algo;

public class InsertIntoACyclicSortedList {
    Node insert(Node head, int insertVal) {
        if (head == null) {
            head = new Node(insertVal, null);
            head.next = head;
            return head;
        }
        Node pre = head, cur = pre.next;
        while (cur != head) {
            if (pre.val <= insertVal && insertVal <= cur.val) break; //found insert point
            //pre max and cur min, insertVal >= pre, or insertVal <= cur
            if (pre.val > cur.val && (pre.val <= insertVal || cur.val >= insertVal)) break;
            pre = cur;
            cur = cur.next;
        }
        pre.next = new Node(insertVal, cur);
        return head;
    }
    class Node {
        int val;
        Node next;
        public Node(int val, Node next) {
            this.val = val;
            this.next = next;
        }
    }
}

