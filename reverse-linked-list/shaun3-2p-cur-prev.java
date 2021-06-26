/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 
 Runtime: 0 ms, faster than 100.00% of Java online submissions for Reverse Linked List.
Memory Usage: 40.6 MB, less than 5.04% of Java online submissions for Reverse Linked List.
 cutting think of tracking with both prev and cur
 much simpler code and thinking
 but if you failed to come up this, it is not easy to solve it
 */
class Solution {
    public ListNode reverseList(ListNode head) {
        
        //prev.--> cur
        //prev <--- cur.-->  next  reverse
        //          prev        cur
        
        ListNode prev = null;
        ListNode cur = head;
        while (cur != null) {
            ListNode next = cur.next;
            cur.next = prev;
            
            prev = cur;
            cur = next;
        }
        
        //cur == null now
        return prev;
    }
}
