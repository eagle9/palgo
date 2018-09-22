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

//jiadai c++, beats 100%
//shaun java, beats 83.40%
public class Solution {
    /**
     * @param ListNode l1 is the head of the linked list
     * @param ListNode l2 is the head of the linked list
     * @return: ListNode head of linked list
     */
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        //create dummy that points to the merged list
        ListNode dummy = new ListNode(-1);
        
        //3 pointers, head for the merged, l1 for list1 and l2 for list2
        ListNode head = dummy;   
        while (l1 != null && l2 != null) {
            if (l1.val <= l2.val) {
                head.next = l1;
                l1 = l1.next;
            }
            else {
                head.next = l2;
                l2 = l2.next;
            }
            head = head.next;
        }
        //l1 == null or l2 == null, connect head to list that still have values
        head.next = l1 != null? l1 : l2;
        
        return dummy.next;
    }
};
