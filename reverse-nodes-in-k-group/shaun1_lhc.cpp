/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//shaun from linhuchong idea, key to understand his reverseNextK
//good example to use dummy node
//fixing code a lot, inside the sub function reverseNextK
// use nk store nk, npk1 to store nk+1 during first loop that check len
//runtime 20ms, faster than 100%, mem less than 100%
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* cur = dummy;
        while (cur) {
            cur = reverseNextK(cur,k);
        }
        return dummy->next;
    }
private:
    //head-> n1 -> n2 -> .. ->nk  -> nk+1
    //nk+1 <- n1 <- n2 <- .. <-nk  <- head    
    // if len < k, return NULL
    ListNode* reverseNextK(ListNode* head, int k) {
        ListNode* cur = head;
        for (int i = 1; i <= k; ++i) {
            cur = cur->next; //cur = n1 to nk
            if (cur == NULL) return NULL;
        }
        ListNode* nk = cur;
        ListNode* nkp1 = nk->next;
        
        //now we have a list whose len >= k
        //this turns into a simple reverse linked list problem
        
        
        //head n1 -> n2 -> .. ->nk  -> nk+1
        //nk+1 <- n1 <- n2 <- .. <-nk  <- head
        ListNode* n1 = head->next;
        ListNode* n2 = n1->next;
        ListNode* prev = NULL;
        cur = n1;
        //for (int i =1; i <= k; ++i) {
        while (cur != nkp1) {
            ListNode* temp = cur->next;
            cur->next = prev;
            
            prev = cur;
            cur = temp;
        }
        
        //connect 
        n1->next = nkp1;
        head->next = nk;
        return n1;
    }
};
