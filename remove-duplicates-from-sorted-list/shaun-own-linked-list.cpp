/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//shaun own idea and code, accepted after bug fix
//bug 1, failed to get that repeated node might not consecutive, so hashset is needed
//bug 2, when delete repeated node, prev and cur update mistakes
//runtime 12ms, faster than 79%, mem less than 5%
class Solution1 {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return head;
        unordered_set<int> visited; 
        visited.insert(head->val);
        ListNode* cur = head->next, *prev = head;
        while (cur) {
            if (visited.count(cur->val)) {
                //prev cur  temp(cur->next) temp->next
                 //  ----------->|
                //             cur
                ListNode* temp = cur->next;
                prev->next = temp;
                delete cur;
                cur = temp;
                
            }else {
                visited.insert(cur->val);
                prev = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};

//sorted, my init understanding is correct, no hash set is needed
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return head;
        
        ListNode* cur = head->next, *prev = head;
        while (cur) {
            if (prev->val == cur->val) {
                //prev cur  temp(cur->next) temp->next
                 //  ----------->|
                //             cur
                ListNode* temp = cur->next;
                prev->next = temp;
                delete cur;
                cur = temp;
            }else {
                prev = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};
