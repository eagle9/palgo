/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
//grandyang recursion, runtime 2ms, faster than 100%
class Solution {
    public ListNode swapPairs(ListNode head) {
        if (head == null|| head.next == null) return head;
        
        //head  head.next    head.next.next
        ListNode t = head.next;
        head.next = swapPairs(head.next.next);
        t.next = head;
        return t;  
    }
}
