/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
Your code should preferably run in O(n) time and use only O(1) memory.
naive algorithm: for each node in A, can we reach this node from B? 
will be O(n*m)

connect A's tail to its head, to make a cycle
from B head, now we can reach A head if intersection exists
but how to locate the intersected node? 
still no clude
check lt3 two pointers, very close

cutting, get len1 and len2,  if there is intersection,  they share the len1 and len2
so let the longer list move first, then move cur1 and cur2 together and check ==

runtie 52ms, faster than 95%, mem less than 37%
*/
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p1 = headA;
        ListNode *p2 = headB;
        ListNode *ret = NULL;
        int len1 = 0;
        int len2 = 0;
        //get len of list1
        while(p1 != NULL) {
            len1++;
            p1 = p1->next;
        }
        //get len of list2
        while(p2 != NULL) {
            len2++;
            p2 = p2->next;
        }
        //start from headA and headB again
        p1 = headA;
        p2 = headB;
        //let the longer list cursor start first, and go len diff steps
        if(len1 > len2) {
            int diff = len1 - len2;
            for(int i = 0;i < diff;i++) {
                p1 = p1->next;
            }
        }else {
            int diff = len2 - len1;
            for(int i = 0;i < diff;i++) {
                p2 = p2->next;
            }
        }
        //now alinged up, move p1 and p2 together and check ==
        while(p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
            
    }
};
