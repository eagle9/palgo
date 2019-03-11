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

class Solution1 {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return NULL;
        auto comp = [](ListNode* a, ListNode* b) { return a->val > b->val;};
        priority_queue<ListNode*, vector<ListNode*>,decltype(comp)> minHeap(comp);
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

/*
not like k sorted array, for list, you can find next node in with current node, so no need to create Entry class
borrow hua's idea and use lambda for comparison
first 
compile error, then MLE, strange, 
cause: if (node->next != NULL) { //while ===> if typo
would rather use Compare class
*/
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //if (lists.size() == 0) return NULL;
        //lambda for comparison
        auto comp = [](ListNode * a, ListNode * b) {
            return a->val > b->val; //java return a.val - b.val, > 0, true, think this way makes feel consistent
        };
        //priority_queue<ListNode*, vector<ListNode*>,decltype(comp)> minHeap(comp);
        struct Compare {
            bool operator()(ListNode* a, ListNode* b) const{
                return a->val > b->val;
            }
        };
        priority_queue<ListNode*, vector<ListNode*>,Compare> minHeap;
        
        for (ListNode * head: lists){
            if (head != NULL) minHeap.push(head);
        }
        ListNode * dummy = new ListNode(-1);
        ListNode * prev = dummy;
        
        //while (minHeap.size() > 0) {
        while (!minHeap.empty()){
            ListNode * node = minHeap.top();
            minHeap.pop();
            prev->next = node;
            prev = node;
            if (node->next != NULL) {
                minHeap.push(node->next);
            }
        };
        return dummy->next;
    }
};
