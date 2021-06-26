/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition of singly-linked-list:
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */
//shaun original idea and code, good example to show why use dummy node
//accepted first sub, beats 99.60% at lintcode
//runtime 8ms, faster than 100%, mem less than 100%
class Solution {
public:
    /**
     * @param l1: ListNode l1 is the head of the linked list
     * @param l2: ListNode l2 is the head of the linked list
     * @return: ListNode head of linked list
     */
    ListNode * mergeTwoLists(ListNode * l1, ListNode * l2) {
        // write your code here
        //good example to show why dummy node is important. We dont know the new head if l1 or l2
        ListNode* dummy = new ListNode(0);
        ListNode *cur1 = l1, *cur2 = l2, *prev = dummy;
        while (cur1 && cur2) {
            if (cur1->val < cur2->val) {
                prev->next = cur1;
                prev = cur1;
                cur1 = cur1->next;
            }else {
                prev->next = cur2;
                prev = cur2;
                cur2 = cur2->next;
            }
           
        }
        if (cur1 == NULL) prev->next = cur2;
        if (cur2 == NULL) prev->next = cur1;
        return dummy->next;
    }
};
