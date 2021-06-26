/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 
 runtime 0ms, faster than 100%, mem less than 100%
 gy reverse linked list idea, simply the carry, time = O(n), space O(1)
 key is to reverse singly linked list correctly and quickly
 
 list pointer from most significant to least
 add to least, carry to most 
 
 if tail val <9, simple, ++ tail val
 if tail val ==9, tail val = 0, carry to prev
 */
class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        if (!head) return head;
        ListNode *rev_head = reverse(head), *cur = rev_head, *pre = cur;
        int carry = 1;
        while (cur) {
            pre = cur;
            int t = cur->val + carry;
            cur->val = t % 10;
            carry = t / 10;
            if (carry == 0) break;
            cur = cur->next;
        }
        if (carry) pre->next = new ListNode(1);
        return reverse(rev_head);
    }
    ListNode* reverse(ListNode *head) {
        if (!head) return head;
        ListNode *dummy = new ListNode(-1), *cur = head;
        dummy->next = head;
        //      cur      t
        //dummy head cur->next   t->next
        while (cur->next) {
            ListNode *t = cur->next;
            cur->next = t->next;
            
            t->next = dummy->next;
            dummy->next = t;
        }
        return dummy->next;
    }
};
