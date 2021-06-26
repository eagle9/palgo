/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//shaun's own idea and implementation, accepted first sub
//cutting: two moving pointers from head, one slow and one fast(2 steps a time), see if they meet
//runtime 12ms, faster than 99%, mem less than 77%
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head; //1 step a time
        ListNode* fast = head; //2 steps a time
        while(fast) {
            slow = slow->next;
            fast = fast->next;
            if (fast == NULL) break; //no cycle, if there is cycle, go on forever without reaching NULL
            fast = fast->next;
            if (slow == fast) return true;
        }
        return false;
    }
};
