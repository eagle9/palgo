/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//shaun's original idea and code, first sub wrong answer, failling corner case?
//yes, found the failling case, each node->val < x, head1 == NULL, you should return head2 instead
//accepted second sub, runtime 8ms, faster than 100%, mem less than 44%
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* head1 = NULL, *head2 = NULL;
        ListNode *prev1 = NULL, *prev2 = NULL;
        ListNode* cur = head;
        bool found_head2 = false, found_head1 = false;
        while (cur) {
        	if (cur->val < x) {
        		if (!found_head1) {
        			found_head1 = true;
        			head1 = cur;
        		}
        		if (prev1) prev1->next = cur;
        		prev1 = cur;
        		
        	}
        	else {
        		if (!found_head2) {
        			found_head2 = true;
        			head2 = cur;
        		}
        		if (prev2) prev2->next = cur;
        		prev2 = cur;
        		
        	}
        	cur = cur->next;
        }
        if (prev1) prev1->next = head2; //connect <x list to >= list
        if (prev2) prev2->next = NULL; //terminate  >=x list
        //return head1;
        return head1?head1:head2;
    }
};
