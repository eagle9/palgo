/**
 * Definition for ListNode
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */

//shaun java adapted from jiadai, beats 86.60%
public class Solution {
    /**
     * @param head: ListNode head is the head of the linked list 
     * @param m: An integer
     * @param n: An integer
     * @return: The head of the reversed ListNode
     */
    public ListNode reverseBetween(ListNode head, int m, int n) {
        // use new keyword to call constructor,  dummy = ListNode(-1) works in c++, not in java
        ListNode dummy = new ListNode(-1);  
        dummy.next = head;
        head = dummy;

        for (int i = 1; i <= m-1; i++) {
            head = head.next;
        }
        // dummy ... head -> node_m
        ListNode prev = head;
        ListNode curr = prev.next;
        ListNode node_m = curr;

        for (int i = m; i <= n; i++) {
            ListNode copy = curr.next; //save curr.next
            curr.next = prev; //reverse
            //update prev, curr
            prev = curr;
            curr = copy;
        }
        //prev (node_n) <-  curr(node_n+1)
        head.next = prev;
        node_m.next = curr;
        return dummy.next;
    }
}
