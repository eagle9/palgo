/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//shaun code from linhuchong 2pointer idea
//dummy node is not needed
//accepted after fixing cur.next   to cur->next
//no use of dummy, prev init with NULL
//runtime 8ms, faster than 100%, mem less than 100%
class Solution {
public:
    ListNode* reverseList1(ListNode* head) {
        //ListNode* dummy = new ListNode(0);
        //dummy->next = head;
        ListNode* cur = head;
        ListNode* prev = NULL;
        //             head  
        //             1 n -> 2 n  -> 3 n-> NULL
        //             ^
        //  prev=NULL  cur
        while (cur) {
            //save cur.next first
            ListNode* temp = cur->next;
            cur->next = prev;
            //move prev and cur at the same time
            prev = cur;
            cur = temp;
        }
        return prev;
    }
    
    //recursive, shaun's own idea, accepted after fixing typo and code to deal with failed cases
    //runtime 12ms, faster than 42%, mem less than 31%
    ListNode* reverseList(ListNode* head) {
        //if (!head) return head;
        if (!head || !head->next) return head; //add single node case
        
        ListNode* head2 = head->next; //save 2nd node
        
        ListNode* res = reverseList(head2);
        head2->next = head;
        head->next = NULL;
        return res;
    }
};
