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

//jiadai c++ Your submission beats 74.40% Submissions!
//jiadai java,Your submission beats 96.40% Submissions!
public class Solution {
    /*
     * @param head: the head of linked list.
     * @return: a middle node of the linked list
     */
    public ListNode  middleNode(ListNode  head) {
        if (head == null) {
            return null;
        }
        ListNode slow = head, fast = head.next;
        while (fast!= null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }
};
