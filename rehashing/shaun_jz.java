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
public class Solution {
    /**
     * @param hashTable: A list of The first node of linked list
     * @return: A list of The first node of linked list which have twice size
     */
    public ListNode[] rehashing(ListNode[] hashTable) {
        // write your code here
        if (hashTable.length <= 0) {
            return hashTable;
        }
        int newcapacity = 2 * hashTable.length;
        ListNode[] newTable = new ListNode[newcapacity];
        for (int i = 0; i < hashTable.length; i++) {
            ListNode cur = hashTable[i];
            while (cur != null) {
                int newindex
                // = (cur.val % newcapacity+ newcapacity) % newcapacity;
                = (cur.val + newcapacity) % newcapacity; //7% test cases passed
                if (newTable[newindex] == null) {
                    newTable[newindex] = new ListNode(cur.val);
                   // newTable[newindex].next = null;
                } else {
                    ListNode dummy = newTable[newindex];
                    while (dummy.next != null) {
                        dummy = dummy.next;
                    }
                    dummy.next = new ListNode(cur.val);
                }
                cur = cur.next;
            }
        }
        return newTable;
    }
}
