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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /*got idea easily from jz, implmented myself, fixing many errors, draw picture and program according to picture is very helpful 
 //finally accepted at lintcode, beat 70%, leetcode timeout error, website issue? 
challenge is to get head and tail at the same time, singly linked list
find the length first by a loop,  head and tail, mid point
then head
        
address the challenge directly, no fear. it often turns into right direction to solution
how to use the data structure to enable us to access head and tail as the same time, then easy move next pair???
use current list next to save it, or use a hash map

draw picture and code from the picture is very helpful for linked list problem
after fixing errors, finally accepted
runtime 48ms, faster than 99.58%, mem less than 67%
*/

class Solution {
public:
    void reorderList(ListNode* head) {
        
        int i = 0; 
        ListNode* cur = head;
        while (cur) {
        	i++;
        	cur = cur->next;
        }
        int len = i;
        cur = head; //reset cur to head again
        i = 1;
        ListNode* prev = NULL;
        while (i <= len) {
        	
            ListNode* temp = cur->next;
        	if (i > len/2) {
        		//reverse
        		cur->next = prev;
        	}
        	prev = cur;
        	cur = temp;
            i++;
        }
        ListNode* cur2 = prev;
        ListNode* cur1 = head;
        ListNode* temp1 = NULL, *temp2 = NULL, *prev2 = NULL;
        for (int i = 1; i <= len/2;++i) {
        	temp1 = cur1->next;
        	temp2 = cur2->next;
            if (prev2) prev2->next = cur1;
        	cur1->next = cur2;
        	
            //cout << cur1->val << " " << cur2->val << endl;
            prev2 = cur2;
            
        	cur1 = temp1;
        	cur2 = temp2;
            
        }
        if (len %2 == 0) {
            if (prev2) prev2->next = NULL;
        }
        else {
        	if (cur2) cur2->next = temp1;
        	if (temp1) temp1->next = NULL;
        }

	}

 };
