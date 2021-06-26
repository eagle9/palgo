/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
delete a node (except the tail) in a singly linked list, given only access to that node.
the challenge is only given the node to be delete, no head or anything
first impression to me, it is impossible
yes: if you delete node with its prev ---> node->next, it is impossible
but how about update current node with its next? so clever 

runtime 12ms, faster than 84%, mem less than 79%
*/
class Solution {
public:
    void deleteNode(ListNode* node) {
        //node temp temp->next
        //node(temp') temp->next
        if (node && node->next) {
            ListNode* temp = node->next;
            node->val = temp->val;
            node->next = temp->next;
            delete temp;
        }
    }
};
