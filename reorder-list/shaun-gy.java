/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
/*
1 2 3 4
1->2 3<-4
1->2
4->3
pretty tricky and details

gy idea
1. 使用快慢指针来找到链表的中点，并将链表从中点处断开，形成两个独立的链表。

2. 将第二个链翻转。

3. 将第二个链表的元素间隔地插入第一个链表中。
*/
class Solution {
    public void reorderList(ListNode head) {
        if (head == null|| head.next == null || head.next.next == null) return;
        ListNode fast = head, slow = head;
        while (fast.next != null && fast.next.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        
        ListNode mid = slow.next;
        slow.next = null;
        
        //reverse 2nd half
        ListNode last = mid, pre = null;
        while (last != null) {
            ListNode next = last.next;
            last.next = pre;
            pre = last;
            last = next;
        }
        
        //head 1->2
        //pre 4->3
        while (head != null && pre != null) {
            
            ListNode next = head.next; //2 save it
            head.next = pre; //1 -> 4
                        
            pre = pre.next;  //3

            head.next.next = next; //4 ->2
            head = next;  //2
        }
    }
}
