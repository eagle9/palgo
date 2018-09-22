/**
 * Definition for ListNode.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int val) {
 *         this.val = val;
 *         this.next = null;
 *     }
 * }
 */ 
 //pobenliu.gitbook.com, beats 78.60%, using head/pq
public class Solution {
    /**
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    public ListNode mergeKLists(List<ListNode> lists) {  
        // write your code here
        if(lists == null ) {
            return null;
        }
        int n = lists.size();
        if (n ==0) return null; 
        
        Queue<ListNode> heap = new PriorityQueue<ListNode>(n, ListNodeComparator);
        // put the head of each list into pq
        for(int i = 0; i < n; i++) {
            ListNode head = lists.get(i);
            if(head != null) {
                heap.add(head);
            }
        }

        ListNode dummy = new ListNode(0);
        ListNode tail = dummy;
        while(!heap.isEmpty()) {
            ListNode head = heap.poll();
            tail.next = head;
            tail = tail.next;
            // if there is a node that follows head, put into pq
            if(head.next != null) {     
                heap.add(head.next);
            }
        }
        return dummy.next;
    }

    private Comparator<ListNode> ListNodeComparator = new Comparator<ListNode>() {
        public int compare(ListNode left, ListNode right) {
            if(left == null) {
                return 1;
            } else if(right == null) {
                return -1;
            }
            return left.val - right.val;
        }
    };  

}
