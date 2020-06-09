# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

from random import randint
class Solution:

    def __init__(self, head: ListNode):
        """
        @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node.
        """
        self.head = head

    def getRandom(self) -> int:
        """
        Returns a random node's value.
        """
        k = 1
        node = self.head
        i = 0
        reservoir = [0 for i in range(k)]
        while i < k and node != None:
            reservoir[i] = node.val
            node = node.next
            i+=1
        i+=1
        while (node != None):
            if randint(0,i-1) < k:
                reservoir[randint(0,k-1)] = node.val
            i+=1
            node = node.next
        return reservoir[0]


# Your Solution object will be instantiated and called as such:
# obj = Solution(head)
# param_1 = obj.getRandom()



