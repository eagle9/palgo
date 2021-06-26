/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */

//Runtime: 12 ms, faster than 61.32% of Java online submissions for Linked List Random Node.
class Solution {

    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    public Solution(ListNode head) {
        this.head = head;
    }
    private ListNode head;
    
    /** Returns a random node's value. */
        //reservior sampling with k
    int getRandom() {
        int k = 1;
        ListNode node = head;
        int i = 0;
        int [] reservoir = new int[k];
        int res = node.val;
        Random rand = new Random();
        //put 0 to k-1 elements into the k-sized reservoir
        while (i < k && node != null) {
            reservoir[i] = node.val;
            node = node.next;
            i++;
        }
        i++; // i == k  =>  i == k+1, this is key

        //till the end of list
        while (node != null) {
            //for probability k/i, take a random index 0 to k-1 to replace with node->val
            //if (rand() % i < k) {
            if (rand.nextInt(i) < k) {
                //reservoir[rand() %k]  = node->val;
                reservoir[rand.nextInt(k)]  = node.val;
            }
            //update i and node for the loop
            i++;
            node = node.next;
        }
        if (reservoir.length > 0) res = reservoir[0];
        return res;// or return reservoir when k > 1;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
