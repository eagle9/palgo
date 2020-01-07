/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
gy reservoir sampling
runtime 40ms, faster than 61%, mem less than 100%


*/
class Solution {
public:
    Solution(ListNode* head) {
        this->head = head;
    }
    int getRandom() {
        int res = head->val, count = 1;
        ListNode *cur = head->next;
        while (cur) {
            count++;
            int j = rand() % count;
            if (j == 0) res = cur->val;
            
            cur = cur->next;
        }
        return res;
    }
private:
    ListNode *head;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
