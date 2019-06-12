# Time:  O(1)
# Space: O(1)
#
# Write a function to delete a node (except the tail) in a singly linked list,
# given only access to that node.
#
# Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node
# with value 3, the linked list should become 1 -> 2 -> 4 after calling your function.
#
# Definition for singly-linked list.
class ListNode:
	def __init__(self, x):
		self.val = x
		self.next = None
	def __str__(self):
		res = ''
		#so bad after long time no practice. forgot to write a loop, you need iterator and exit condition
		node = self
		while node is not None:
			res += '%d->' % node.val
			node = node.next
		return res

class Solution:
    # @param {ListNode} node, node is ref in the list
    # @return {void} Do not return anything, modify node in-place instead.
	# idea is to not to remove node, but replace node with node.next, then remove node.next
	# what if node.next is None? not the case. specifically, remove the 3rd node from a long list
    def deleteNode(self, node):
        if node and node.next:
            node_to_delete = node.next
            node.val = node_to_delete.val
            node.next = node_to_delete.next
            del node_to_delete
head = ListNode(1)
prev = head
node_to_del = None
for  i in range(2,5):
	node = ListNode(i)
	if i == 3: node_to_del = node
	prev.next = node
	prev = node
print head
Solution().deleteNode(node_to_del)
print head
