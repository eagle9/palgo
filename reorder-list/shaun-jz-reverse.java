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
1->4 -> 2-> 3
pretty tricky and details
*/
class Solution {
    public void reorderList(ListNode head) {
        int i = 0; 
        ListNode cur = head;
        while (cur != null) {
        	i++;
        	cur = cur.next;
        }
        int len = i;
        
        cur = head; //reset cur to head again
        i = 1;
        ListNode prev = null;
        
        //reverse second half of the list
        while (i <= len) {
        	//prev cur cur.next(temp)
            ListNode temp = cur.next; //save cur.next as it will be changed
        	if (i > len/2) {
        		//reverse
        		cur.next = prev;
        	}
            //move forward
        	prev = cur;
        	cur = temp;
            i++;
        }
        ListNode cur2 = prev; //tail
        ListNode cur1 = head;
        ListNode temp1 = null;
        ListNode temp2 = null, prev2 = null; //prev for cur2
        for (i = 1; i <= len/2;++i) {
        	temp1 = cur1.next;
        	temp2 = cur2.next;
            
            if (prev2 != null) prev2.next = cur1;
        	cur1.next = cur2;
        	
            //cout << cur1->val << " " << cur2->val << endl;
            prev2 = cur2;
            
        	cur1 = temp1;
        	cur2 = temp2;
            
        }
        if (len %2 == 0) {
            if (prev2 != null) prev2.next = null;
        }
        else {
        	if (cur2 != null) cur2.next = temp1;
        	if (temp1 != null) temp1.next = null;
        }
    }
}
