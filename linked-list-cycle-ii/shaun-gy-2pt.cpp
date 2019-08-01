/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
cutting slow and fast pointers
slow 1 step, fast 2 steps, till slow == fast
then slow reset to head, fast from where it was, both 1 step each time, till meet, which is the start of the cylce
runtime 12ms, faster than 78%, mem less than 91%

math:
https://www.cnblogs.com/hiddenfox/p/3408931.html
head to start of cycle = a
start to meet = b, meet to start = c
第一次相遇时slow走过的距离：a+b，fast走过的距离：a+b+c+b。

因为fast的速度是slow的两倍，所以fast走的距离是slow的两倍，有 2(a+b) = a+b+c+b，可以得到a=c（这个结论很重要！）。
我们已经得到了结论a=c，那么让两个指针分别从X(head)和Z(first meet)开始走，每次走一步，那么正好会在Y(start)相遇！也就是环的第一个节点。
*/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }
        if (!fast || !fast->next) return NULL;
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};
