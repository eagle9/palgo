/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 Runtime: 0 ms, faster than 100.00% of Java online submissions for Remove Duplicates from Sorted List.
Memory Usage: 39.2 MB, less than 7.14% of Java online submissions for Remove Duplicates from Sorted List.

sorted, no need for hashmap, just compare to prev
 
 */
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
         if (head == null) return head;

        ListNode cur = head.next, prev = head;
        while (cur!=null) {
            if (prev.val == cur.val) {
                //prev cur  temp(cur->next) temp->next
                 //  ----------->|
                //             cur
                ListNode temp = cur.next;
                prev.next = temp;
                //delete cur;
                cur = temp;
            }else {
                prev = cur;
                cur = cur.next;
            }
        }
        return head;

    }
}
