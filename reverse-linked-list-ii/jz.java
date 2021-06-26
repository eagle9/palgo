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

//jz beats 78%
public class Solution {
    public ListNode reverseBetween(ListNode head, int m, int n) {
		//assume 1<=m <=n <= len
        if (m >= n ) return head; //no nodes need to be reversed
        if (head == null) return null; //empty list 
        //add dummy node ,why? 
        //head ....    ===>  dummy -> head ....
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        head = dummy;
        
		//get to mth node
		//head 1 2 3 .... m .... n .... len
        for (int i = 1; i < m; i++) { // 1 next   2  next    3, that's why i < m
            if (head == null) { //list is shorter than m, so return null
                return null;
            }
            head = head.next;
        }
		//next m-1 times, get to mth node, if list len < m, return 
        // 1 ->2 -> 3 -> ... ->m-1 ->m -> ... -> n -> n+1 ....-> L
        // 1    2   3          m-1   m <- .... <-n
        //                     m-1->n            m -> n+1
        
        ListNode premNode = head;    //pre m node
        ListNode mNode = head.next;  

        //move nNode and postnNode together from mNode
        ListNode nNode = mNode, postnNode = mNode.next;
        for (int i = m; i < n; i++) {
            if (postnNode == null) {  //len < n, could not do the reverse, return
                return null;
            }
            ListNode temp = postnNode.next;
            postnNode.next = nNode; //reverse 
            nNode = postnNode; //update 1 step forward 
            postnNode = temp; //update 1 step forward
        }
        mNode.next = postnNode;
        premNode.next = nNode;
       
        //return original head 
        return dummy.next;
    }
}
