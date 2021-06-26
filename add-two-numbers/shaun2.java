/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
/*
Runtime: 1 ms, faster than 100.00% of Java online submissions for Add Two Numbers.
Memory Usage: 39.7 MB, less than 99.37% of Java online submissions for Add Two Numbers.
*/
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(-1);
        ListNode prev = dummy;
        ListNode cur1 = l1, cur2 = l2;
        int carry = 0;
        while (cur1 != null || cur2 != null) {
            int val = carry;
            if (cur1 != null) {
                val += cur1.val;
                cur1 = cur1.next;
            }
            if (cur2 != null) {
                val += cur2.val;
                cur2 = cur2.next;
            }
            carry = val / 10;
            val = val % 10;
            ListNode node = new ListNode(val);
            prev.next = node;
            prev = node;
        }
        //cur1 == null and cur2 == null
        if (carry > 0) {
            ListNode node = new ListNode(carry);
            prev.next = node;
            prev = node;
        }
        prev.next = null;
        return dummy.next;
        
    }
}
