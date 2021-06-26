/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//shaun's own idea, accepted after fixing typo p.next ==> p->next
//fixing access p->next when p is NULL
//runtime 4ms, faster than 100%, mem less than 100%
//               m          n
/*        prev1 tail1     head1 after1 
 *         ---------------->
 *    1 -> 2 ->  3 -> 4 ->  5 ->  6   -> 7
 *            <- 3 <-4 <- 5
 *               ----------------->
 *            prev  cur temp      
 *
 *
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* cur = head;
        ListNode* prev = NULL;
        ListNode* prev1 = NULL;
        ListNode* after1 = NULL; //prev node before mn list
        ListNode* head1 = NULL;
        ListNode* tail1 = NULL; //the node after mn list
        for (int i = 1; cur; i++) {
            ListNode * temp = cur->next;
            if (i >= m && i <= n) {
                if (i == m) {
                    prev1 = prev;
                    tail1 = cur;
                }
                if (i == n) {
                    head1 = cur;
                    after1 = cur->next;
                }
                cur->next = prev;
            }
            prev = cur;
            cur = temp;
        }
        if (prev1) prev1->next = head1;
        if (tail1) tail1->next = after1;
        if (m == 1) return head1;
        return head;
        
    }
};
