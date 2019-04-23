/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//shaun's own idea and code, runtime 28ms, faster than 93%, mem less than 100%

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(0);
        ListNode* prev = dummy;
        
        struct Compare {
            bool operator() (ListNode* a, ListNode* b) const {
                return a->val > b->val; //larger val in front, so pq pop smaller first
            }
        }; //; is required here
        
        priority_queue<ListNode*, vector<ListNode*>,Compare> min_heap;
        for (ListNode* head: lists) {
            if (head) min_heap.push(head);  //if head to prevent NULL pushed into heap
        }
        
        while (!min_heap.empty()) {
            ListNode* node = min_heap.top(); min_heap.pop();
            prev->next = node;
            prev = node;
            if (node->next) {
                min_heap.push(node->next);
            }
        }
        prev->next = NULL;
        return dummy->next;
    }
};
