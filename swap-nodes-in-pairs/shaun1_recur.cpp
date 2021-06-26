//shaun try recursion, accepted after fixing a little 
//recursion is much easier
//runtime 4ms, faster than 100%, mem less than 100%
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        //empty or single node
        if (head == NULL || head->next == NULL) return head;
        
        //two or more nodes
        ListNode* node1 = head;
        ListNode* node2 = node1->next;
        if (node2) {
            ListNode* node3 = swapPairs(node2->next);
            node1->next = node3;
        }
        node2->next = node1;
        return node2;
    }
};
