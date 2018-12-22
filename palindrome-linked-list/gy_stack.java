/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    //grandyang, shaun java, beats 30%
    public boolean isPalindrome(ListNode head) {
        if (head == null || head.next == null) return true;
        ListNode slow = head, fast = head;
        Stack<Integer> s = new Stack<>();
        s.push(head.val);
        // 1  2  3  4  5  6
        //    s  f
        //       s     f
        while (fast.next != null && fast.next.next != null) {
            slow = slow.next;
            fast = fast.next.next;
            s.push(slow.val);
        }
        //s: 123
        //fast.next == null or fast.next.next == null
        //end 5, fast.next == null
        if (fast.next == null) s.pop(); //odd length, pop middle
        //s: 12 when odd
        //s: 123 when even
        //slow = 3, 
        while (slow.next != null) {
            //slow = 4
            slow = slow.next;
            //tmp = 2
            int tmp = s.pop();
            if (tmp != slow.val) return false;
        }
        return true;
    }
};
