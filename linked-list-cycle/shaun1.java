/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 
 Runtime: 0 ms, faster than 100.00% of Java online submissions for Linked List Cycle.
Memory Usage: 42.2 MB, less than 5.71% of Java online submissions for Linked List Cycle.
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        ListNode slow = head; //1 step a time
        ListNode fast = head; //2 steps a time
        while(fast != null) {
            slow = slow.next;
            fast = fast.next;
            if (fast == null) break; //no cycle, if there is cycle, go on forever without reaching NULL
            fast = fast.next;
            if (slow == fast) return true;
        }
        //other cases ==> false
        return false;
    }
}
