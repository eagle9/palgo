/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
cutting, introduce dummy since the head might be changed
cur    cur->next
            t       t->next

cur  --------------- t->next
        delete t

runtime 28ms, faster than 75%, mem less than 14%
*/
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        //use a dummy, since head might be deleted
        ListNode *dummy = new ListNode(-1), *cur = dummy;
        dummy->next = head;
        
        //cur    cur->next
        //          t       t->next
        while (cur->next) {
            if (cur->next->val == val) {
                ListNode *t = cur->next;
                cur->next = t->next;  //pre  ----____---- t->next
                t->next = NULL;  //release t
                delete t;
            } else {
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};
