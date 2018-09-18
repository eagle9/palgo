//jz, Your submission beats 82.20% Submissions!
public class Solution {
    /**
     * @param head: The head of linked list.
     * @return: The new head of reversed linked list.
     */
    public ListNode reverse(ListNode head) {
        ListNode prev = null;
		//head is the iterator, prev is one step slower than head 
		// null .... prev head ....>
        while (head != null) {
            ListNode temp = head.next; //save head.next 
            head.next = prev;  //head.next --> prev
            prev = head; //prev move 1 step forward
            head = temp; //head move 1 step forward
        }
		//null... prev head==null
        return prev;
    }
}
