/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    //grandyang, two pointers, reverse list, beats 98%
    public boolean isPalindrome(ListNode head) {
        if (head == null || head.next == null) return true;
        ListNode slow = head, fast = head;
        //1 2 3 4 5 6
        //    f   f
        //    s
        //1 2 3 
        //6 5 4 : reverse the list 456
        //1 2 3 4 5
        //    s   f
        //12 compare with 54
        //no matter odd or even, reverse s.next to end
         while (fast.next != null && fast.next.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        
        //last is the head of sublist we want to reverse
        //pretty tricky to revese linked list
        ListNode last = slow.next, head1 = head;
        //reverse 2nd half of the list
        //slow ->last-> tmp
        // .                  last 
        //        slow < tmp
        /*
        
        while (last.next != null) {
            ListNode tmp = last.next;
            last.next = tmp.next;
            tmp.next = slow.next;
            slow.next = tmp;
        }*/
        ListNode head2 = reverseList(last);
        while (head2 != null) {
            if (head1.val != head2.val) return false;
            head2 = head2.next;
            head1 = head1.next;
        }
        return true;
    }
    public ListNode reverseList(ListNode head) {
        
        // 1 2 3 4
        // 4 3 2 1
        // null <- 1 <- 2 <- 3 <- 4
        //prev =null, head->1
        ListNode prev = null;
        //head is the iterator, prev is one step slower than head 
        // null .... prev head ....>
        while (head != null) {
            ListNode next = head.next; //save head.next 
            
            head.next = prev;  //head.next --> prev
            prev = head; //prev move 1 step forward
            head = next; //head move 1 step forward
        }
        //null... prev head==null
        return prev;
    }
};
