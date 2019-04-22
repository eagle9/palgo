/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//shaun tried iteration, wrong answer, kind of messy feeling
//draw picture on paper and run typical cases, it helps a lot
//finally accepted, runtime 4ms, faster than 100%, mem less than 100%
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        //if empty or single node
        if (head == NULL || head->next == NULL) return head;
        
        //now two more nodes
        ListNode* res = head->next;
        
        ListNode* cur = head; //cursor
        ListNode* prev = NULL; //prev, used to connect pairs
        
        //n1 -> n2 -> n3
        // .          n1 -> n2
        //two nodes at a time
        while (cur && cur->next) {
            ListNode* n1 = cur;
            ListNode* n2 = cur->next;
            ListNode* n3 = n2? n2->next: NULL;
            
            n2->next = n1; //revese
            if (prev) prev->next = n2; //connect two pairs
            
            cur = n3; //update 
            prev = n1;
        }
        if (cur) { //one node left
            if (prev) prev->next = cur;
        }else { //no nodes left, terminate the new list
            prev->next = NULL;
        }
        
        return res;
    }
};
