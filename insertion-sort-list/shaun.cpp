/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*

main test is linked list manipulation
given a list, take one node at a time,  
create a dummy node as the head of a new list, 
insert the node to the new list according to its value: find the proper position from new list head, insert the node
return dummy.next 
simply idea, but tricky implemenation with linked list

Runtime: 48 ms, faster than 76.19% of C++ online submissions for Insertion Sort List.
Memory Usage: 6.2 MB, less than 0.81% of C++ online submissions for Insertion Sort List.
*/
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode * dummy = new ListNode(-1);
        ListNode * cur = dummy;
        while (head) {
            //head -> temp
            ListNode *temp = head->next;
            cur = dummy; //reset cur to the new list head
            while (cur->next && cur->next->val <= head->val ) {
                cur = cur->next;
            }
            //now cur ... cur->next->val 
            //      <=        >
            // cur -> head -> cur->next
            head->next = cur->next;
            cur->next = head;
            
            
            head = temp; //move forward along the input list
        }
        return dummy->next;
    }

};
