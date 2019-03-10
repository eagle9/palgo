/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
shaun's c++ from translate from java
with lots of api checking online, anyhow, accepted at last
runtime 28ms, faster than 98%

then not use entry(node,next), directly use minHeap<ListNode*>
accepted, runtime 28ms, faster than 98%
*/
struct NodeCompare {
    bool operator()(ListNode* a, ListNode* b) { 
        //order listNode* from large to small, true in front
        return a->val > b->val;
    };
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return NULL;
        //auto comp = [](ListNode* a, ListNode* b) { return a->val > b->val;};
        //priority_queue<ListNode*, vector<ListNode*>,decltype(comp)> minHeap(comp);
        //prefer to use Compare class, rather than lambda
        priority_queue<ListNode*, vector<ListNode*>, NodeCompare> minHeap;
        for (auto head: lists) {
            if (head != NULL) {
                minHeap.push(head);
            }
        }
        ListNode * dummy = new ListNode(-1);
        ListNode * prev = dummy;
        while (!minHeap.empty()) {
            ListNode* node = minHeap.top();
            minHeap.pop();
            prev->next = node;
            prev = node;
            if (node->next != NULL) {
                minHeap.push(node->next);
            }
            
        }
        return dummy->next;
    }
};
