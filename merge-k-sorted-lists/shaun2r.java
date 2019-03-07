/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
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


class Entry {
    
    ListNode next;
    ListNode node; 
    public Entry(ListNode node, ListNode next) {
        this.node = node;
        this.next = next;
    }
    
}
/*
shaun's own idea using k-size minHeap
accepted at lintcode after added lists null and size == 0 case
beats 53%

accepted at leetcode after added lists null and size = 0 case 
runtime 10ms, faster than 69%

key lesson, don't forget null or empty input
*/
public class Solution {
    private Comparator<Entry> ecmp = new Comparator<Entry>() {
        public int compare(Entry a, Entry b) {
            return a.node.val - b.node.val;
        }
    };
    
    public ListNode mergeKLists(ListNode[] lists) { 
        if (lists == null || lists.length == 0) return null;
        
        PriorityQueue<Entry> minHeap = new PriorityQueue<Entry>(lists.length, ecmp);
        for (ListNode head: lists) {
            if (head != null) {
                Entry e = new Entry(head, head.next);
                minHeap.offer(e);
            }
        }
        ListNode dummy = new ListNode(-1);
        ListNode prev = dummy;
        while (minHeap.size() > 0) {
            Entry e = minHeap.poll();
            //prev  e.node
            prev.next = e.node;
            prev = e.node;
            if (e.next != null) {
                minHeap.offer(new Entry(e.next, e.next.next));
            }
            
        }
        
        return dummy.next;
    }
}

