/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
 //jz idea, newIndex = (keyval + newcapacity)% newcapacity
 //shaun read and modified, beats 87%
class Solution {
public:
    /**
     * @param hashTable: A list of The first node of linked list
     * @return: A list of The first node of linked list which have twice size
     */    
    vector<ListNode*> rehashing(vector<ListNode*> hashTable) {
        int newcapacity = 2 * hashTable.size();
        vector<ListNode*> newTable(newcapacity);
        
        for (int i = 0; i < hashTable.size(); i++) {
            ListNode* cur = hashTable[i];
            while (cur) {
                int newindex
                // = (cur.val % newcapacity+ newcapacity) % newcapacity;
                = (cur->val + newcapacity) % newcapacity; //7% test cases passed
                if (newTable[newindex] == NULL) {
                    newTable[newindex] = new ListNode(cur->val);
                   // newTable[newindex].next = null;
                } else {
                    ListNode* dummy = newTable[newindex];
                    while (dummy->next) {
                        dummy = dummy->next;
                    }
                    dummy->next = new ListNode(cur->val);
                }
                cur = cur->next;
            }
        }
        return newTable;
    }
};
