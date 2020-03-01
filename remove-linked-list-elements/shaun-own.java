/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 
 Runtime: 1 ms, faster than 91.47% of Java online submissions for Remove Linked List Elements.
 shaun's own idea, accepted first pass
 */

class Solution {
    public ListNode removeElements00(ListNode head, int val) {
        ListNode dummy = new ListNode(-1);
        dummy.next = head;
        ListNode prev = dummy;
        ListNode cur = head;
        while (cur != null) {
            if (cur.val == val) {
                cur = cur.next;
                prev.next = cur;
            }else {
                cur = cur.next;
                prev = prev.next;
            }
        }
        return dummy.next;
    }
    //adapted upon gy's idea
    public ListNode removeElements(ListNode head, int val) {
        ListNode dummy = new ListNode(-1);
        dummy.next = head;
        
        ListNode cur = dummy;
        while (cur.next != null) {
            if (cur.next.val == val) {
                ListNode temp = cur.next;
                cur.next = temp.next;
                //delete temp
            }else {
                cur = cur.next;
                
            }
        }
        return dummy.next;
    }
}
