/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*shaun implemented divide and conquer idea
accepted first submission, very slow somehow
runtime 628ms, faster than 5%, memory usage less than 5%
the cause of slow running is helper(vector<ListNode*> lists, int start, int end)
checked with grandyang version, added pass by reference
pass as reference causes huge difference in speed from 5% to 100%, if not by ref, have to copy entire lists for each call, wow
*/

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (n == 0) return NULL;
        //now n >= 1
        return helper(lists,0,n-1);
        
        
    };
    
    ListNode* helper(vector<ListNode*> lists, int start, int end) {
        if (start == end) return lists[start];
        
        int mid = start + (end - start)/2;
        ListNode* left = helper(lists, start, mid);
        ListNode* right = helper(lists, mid+1,end);
        return merge2(left,right);
    }
    
    //merge two sorted linked list, with dummy and without dummy
    ListNode* merge2(ListNode* left, ListNode* right) {
        //ListNode* dummy = new ListNode(0);
        //ListNode * prev = dummy;
        if (left == NULL) return right;
        if (right == NULL) return left;
        //left != NULL && right != NULL
        ListNode* head = NULL;
        if (left->val < right->val) {
            head = left;
            left = left->next;
        }else {
            head = right;
            right = right->next;
        }
        ListNode* prev = head;
        while (left != NULL && right != NULL) {
            if (left->val < right->val) {
                prev->next = left;
                prev = left;
                left = left->next;
            }else {
                prev->next = right;
                prev = right;
                right=right->next;
            }
        }
        if (left == NULL) {
            prev->next = right;
        }else { //right == NULL
            prev->next = left;
        }
        return head;
        //return dummy->next;
        
    }
};
