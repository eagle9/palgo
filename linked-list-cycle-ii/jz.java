/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
//jz idea and code, why????
//runtime 0ms, faster than 100%, mem less than 41%
public class Solution {
    public ListNode detectCycle(ListNode head) {
        if (head == null || head.next==null) {
            return null;
        }

        ListNode fast, slow;
        fast = head.next;    		//快指针
        slow = head;				//慢指针
        while (fast != slow) {		//快慢指针相遇
            if(fast==null || fast.next==null)
                return null;
            fast = fast.next.next;
            slow = slow.next;
        } 
        
        while (head != slow.next) {  //同时移动head和慢指针
            head = head.next;
            slow = slow.next;
        }
        return head;				//两指针相遇处即为环的入口
    }
}
