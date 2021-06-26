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
*/
class Entry {
public:
    ListNode *node;
    ListNode *next;
    Entry(ListNode *node1, ListNode *next1) {
        node = node1;
        next = next1;
    }
};
struct CompareEntry { //must be struct
    bool operator() (const Entry & a, const Entry & b) const {
        return a.node->val > b.node->val; // a > b ==> ascending
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return NULL;
        priority_queue<Entry, vector<Entry>, CompareEntry> minHeap;
        for (auto head: lists) {
            if (head != NULL) {
                Entry e = Entry(head, head->next); //java = new Entry
                minHeap.push(e);
            }
        }
        ListNode * dummy = new ListNode(-1);
        ListNode * prev = dummy;
        while (!minHeap.empty()) {
        //while (minHeap.size() > 0) {
            Entry e = minHeap.top();
            minHeap.pop();
            prev->next = e.node;
            prev = e.node;
            if (e.next != NULL) {
                minHeap.push(Entry(e.next, e.next->next));
            }
        }
        return dummy->next;
    }
};

