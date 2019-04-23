/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    //return the node where the cycle begins
    //idea: from 1, we can use slow and fast to find the cycle
    //now let's locate the start
    //first sub TLE
    //2nd and 3rd sub still TLE, kidding me!!!! idea is right, can't get impl right????!!!!
    //finally use do while loop to ensure all nodes inside cycle is used for comparison
    //also make sure cur == slow break out of 2 loops
    //finally accepted, runtimes 48ms, faster than 5%, mem less than 54%
    ListNode *detectCycle(ListNode *head) {
        //detech cycle first and goes to the node inside the cycle
        ListNode* slow = head;
        ListNode* fast = head;
        
        bool has_cycle = false;
        while (fast) {
            slow = slow->next;
            fast = fast->next;
            if (fast == NULL) {
                has_cycle = false;
                break;
            }
            fast = fast->next;
            if (slow == fast) {
                has_cycle = true;
                break;
            }
        }
        if (!has_cycle) return NULL;
        //has cycle now, slow == fast, a node inside the cycle
        ListNode * cur = head;
        
        while (true) {
            //move slow around the cycle
            do {
                if (cur == slow) {
                    return cur;
                };  //only break out of 1 loop
                slow=slow->next; //try all nodes in the cycle to see if it is equals to cur
            }while ( slow != fast);
            
            //slow == fast now, went all nodes 
            //move cur to next, and slow to next
            cur = cur->next; 
            
        }
        return NULL;
    }
};
