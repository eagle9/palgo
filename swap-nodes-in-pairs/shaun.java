/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
//shaun first try, wrong answer
class Solution {
    public ListNode swapPairs(ListNode head) {
        helper(head);
        return head;
        
    }
    private void helper(ListNode head) {
        //head a b
        if (head == null) return;
        ListNode a = head.next;
        if (a == null) return;
        ListNode b = a.next;
        if (b == null) return;
        
        
        ListNode temp = head;
        head = a;
        head.next = temp;
        temp.next = b;
        helper(b);
    }
    
}
