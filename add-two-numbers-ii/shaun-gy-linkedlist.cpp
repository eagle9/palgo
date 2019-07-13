/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//grandyang linked list idea
// different from 1, low digit is at tail, high digit at head
//runtime 20ms, faster than 95%, mem less than 24%
//cutting: natural use stack to put tail at the top of each stack, the pop two stacks at the same time,  weave list from tail to head, consider dealing with carry 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        while (l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }
        int sum = 0;
        ListNode *res = new ListNode(0);
        //now the top of each stack stores low digit, add digit from low to high
        //result list node creation from tail to head
        while (!s1.empty() || !s2.empty()) {
            if (!s1.empty()) {sum += s1.top(); s1.pop();}
            if (!s2.empty()) {sum += s2.top(); s2.pop();}
            res->val = sum % 10;
            ListNode *head = new ListNode(sum / 10); //sum /10 is carry to store at higher node
            head->next = res;
            //update loop variable .  list: head -> res
            //                        move direction: <-  
            res = head;
            sum /= 10; //carry to higher digit, for next loop
        }
        //don't want leading 0
        return res->val == 0 ? res->next : res;
    }
};
