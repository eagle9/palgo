/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


/*
not like k sorted array, for list, you can find next node in with current node, so no need to create Entry class
borrow hua's idea and use lambda for comparison
first 
compile error, then MLE, strange
*/
/*
not like k sorted array, for list, you can find next node in with current node, so no need to create Entry class
borrow hua's idea and use lambda for comparison
first 
compile error, then MLE, strange, 
cause: if (node->next != NULL) { //while ===> if typo
finally accepted, 28ms, faster than 98%
*/
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //if (lists.size() == 0) return NULL;
        //lambda for comparison
        auto comp = [](ListNode * a, ListNode * b) {
            return a->val > b->val; //java return a.val - b.val, > 0, true, think this way makes feel consistent
        };
        priority_queue<ListNode*, vector<ListNode*>,decltype(comp)> minHeap(comp);
        for (ListNode * head: lists){
            if (head != NULL) minHeap.push(head);
        }
        ListNode * dummy = new ListNode(-1);
        ListNode * prev = dummy;
        
        while (minHeap.size() > 0) {
            ListNode * node = minHeap.top();
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

//hua c++ code works, not mine, 
class Solution1 {
public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode dummy(0);
    ListNode *cur = &dummy;
    
    auto comp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
    priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> q(comp);
    
    for (ListNode* list : lists) 
      if (list) q.push(list);
    
    while (!q.empty()) {
      cur->next = q.top(); q.pop();      
      cur = cur->next;
      if (cur->next) q.push(cur->next);
    }
    return dummy.next;
  }
};

