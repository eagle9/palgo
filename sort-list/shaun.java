/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
/*
Runtime: 4 ms, faster than 93.84% of Java online submissions for Sort List.
Memory Usage: 30.5 MB, less than 28.00% of Java online submissions for Sort List.

shaun java code
*/
class Solution {
    public ListNode sortList(ListNode head) {
        if (head == null || head.next == null) return head;
        ListNode pre = head, slow = head, fast = head;
        while (fast != null && fast.next != null) {
            pre = slow;
            slow = slow.next;
            fast = fast.next.next;
        }
        
        pre.next = null;
        return merge(sortList(head), sortList(slow));
    }
    public ListNode merge(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(-1);
        ListNode cur = dummy;
        while (l1 != null && l2 != null) {
            if (l1.val < l2.val) {
                cur.next = l1;
                l1 = l1.next;
            }else {
                cur.next = l2;
                l2 = l2.next;
            }
            cur = cur.next;
        }
        
        if (l1 != null)  cur.next = l1;
        if (l2 != null)  cur.next = l2;
        return dummy.next;
    }
}


