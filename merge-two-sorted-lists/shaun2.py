# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
#Runtime: 40 ms, faster than 23.48% of Python3 online submissions for Merge Two Sorted Lists.
class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        dummy = ListNode(-1)
        cur = dummy
        p1,p2 = l1,l2
        while (p1 and p2):
            if p1.val < p2.val:
                cur.next = p1
                p1 = p1.next
            else:
                cur.next = p2
                p2 = p2.next
            cur = cur.next
        if p1 != None:
            cur.next = p1
        else:
            cur.next = p2
        return dummy.next
        
