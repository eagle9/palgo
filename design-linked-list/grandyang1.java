//grandyang v1, beats 55%
class MyLinkedList {
    private Node head, tail;
    private int size;
    
    class Node {
        int val;
        Node next;
        public Node(int x, Node n){
            this.val = x;
            this.next = n;
        }
    };
    
    /** Initialize your data structure here. */
    public MyLinkedList() {
        head = null;
        size = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    public int get(int index) {
        if (index < 0 || index >= size) return -1;
        Node cur = head;
        for (int i = 0; i < index; ++i) 
            cur = cur.next;
        return cur.val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    public void addAtHead(int val) {
        Node t = new Node(val, head);
        head = t;
        ++size;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    public void addAtTail(int val) {
        Node cur = head;
        while (cur.next != null) 
            cur = cur.next;
        cur.next = new Node(val, null);
        ++size;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    public void addAtIndex(int index, int val) {
        if (index < 0 || index > size) return;
        if (index == 0) {
            addAtHead(val); 
            return;
        }
        Node cur = head;
        for (int i = 0; i < index - 1; ++i) 
            cur = cur.next;
        Node t = new Node(val, cur.next);
        cur.next = t;
        ++size;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    public void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;
        if (index == 0) {
            head = head.next;
            --size;
            return;
        }
        Node cur = head;
        for (int i = 0; i < index - 1; ++i) 
            cur = cur.next;
        cur.next = cur.next.next;
        --size;
    }
    

};
