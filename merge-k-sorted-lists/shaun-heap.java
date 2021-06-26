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
//shaun own idea with min heap
//Runtime: 4 ms, faster than 79.72% of Java online submissions for Merge k Sorted Lists.
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        ListNode dummy = new ListNode(0);
        ListNode prev = dummy;
        PriorityQueue<ListNode> minHeap = new PriorityQueue<>((x,y) -> {
            return Integer.compare(x.val, y.val);
        });
        for (ListNode head: lists) {
            if (head != null) minHeap.offer(head);  //if head to prevent NULL pushed into heap
        }
        while (!minHeap.isEmpty()) {
            ListNode node = minHeap.poll();
            prev.next = node;
            prev = node;
            if (node.next != null) {
                minHeap.offer(node.next);
            }
        }
        prev.next = null;
        return dummy.next;
            
    }
}

