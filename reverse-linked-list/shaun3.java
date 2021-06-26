/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 
 
 Shaun may 17 forgot the details in the past and stuggled and get accepted
 good experience to stay calm and tackle
 Runtime: 0 ms, faster than 100.00% of Java online submissions for Reverse Linked List.
Memory Usage: 40.5 MB, less than 5.04% of Java online submissions for Reverse Linked List.
 
 
 */
class Solution {
    public ListNode reverseList(ListNode head) {
        ListNode a = head;
        
        if (a == null || a.next == null) return a;
        
        ListNode b = a.next;
        ListNode dummy = null;
        
        while (a != null && b != null) {
            //a.<-   b   -->c
            //       a     b      
            
            ListNode c = b.next; //save 
            b.next = a;
            dummy = a; //store it to record the new head
            a = b; //update
            b = c;
            
        }
        //a -->b
        //a == null or b == null
        head.next = null; //terminate
        
        //----|a b
        if (a==null) return dummy;
        //a != null && b == null
        return a;
        
    }
}
