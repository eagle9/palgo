/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
  slow move one step,  fast more two steps a time, break the list into two smaller lists
  head->    pre|  slow->

Runtime: 76 ms, faster than 29.27% of C++ online submissions for Sort List.
Memory Usage: 32.2 MB, less than 0.99% of C++ online submissions for Sort List.

shaun c++ code
*/
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        //if the list is empty or just one node, 
        if (head == NULL || head->next == NULL ) return head;
        ListNode *pre = head; //node before slow, used to terminate first half list
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = NULL;
        return merge(sortList(head), sortList(slow));
    }
    ListNode * merge(ListNode * l1, ListNode * l2) {
        ListNode * dummy = new ListNode(-1);
        ListNode * cur = dummy;
        while (l1 && l2 ) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
                
            }else {
                cur->next = l2;
                l2 = l2->next;
                
            }
            cur = cur->next;
        }
        if (l1) cur->next = l1;
        if (l2) cur->next = l2;
        return dummy->next;
    }
};

