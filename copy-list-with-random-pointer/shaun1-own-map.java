/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}

idea forming:
copy all nodes with val first
then pointers
shaun own idea accepted after 1 minor bug fix cur=cur.next
Runtime: 1 ms, faster than 14.35% of Java online submissions for Copy List with Random Pointer.
Memory Usage: 43 MB, less than 5.61% of Java online submissions for Copy List with Random Pointer.
*/

class Solution {
    public Node copyRandomList(Node head) {
        Node cur = head;
        Node prev = null;
        Node dummy = new Node(-1);
        prev = dummy;
        Map<Node,Node> map = new HashMap<>();
        while (cur != null) {
            Node copy = new Node(cur.val);
            map.put(cur, copy);
            prev.next = copy;
            cur = cur.next;
            prev = copy;
        }
        cur = head;
        while (cur!=null) {
            Node copy = map.get(cur);
            copy.random = map.get(cur.random);
            cur = cur.next;
        }
        return dummy.next;
    }
}
