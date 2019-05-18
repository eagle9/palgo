/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//shaun's own idea and accepted second sub
//runtime 20ms, faster than 99%, mem less than 63%
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //digits stored low digit first
        
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        ListNode* dummy = new ListNode(0);
        ListNode* prev = dummy;
        int carry = 0;
        while (cur1 || cur2 || carry) {
            int sum = carry; //carry from prev digits
            if (cur1) {
                sum += cur1->val;
                cur1 = cur1->next;
            }
            if (cur2) {
                sum += cur2->val;
                cur2 = cur2->next;
            }
            int val = sum % 10;
            carry = sum/10;
            ListNode * node = new ListNode(val);
            prev->next = node;
            prev = node;
        }
        
        prev->next = NULL;
        return dummy->next;
    }
};
