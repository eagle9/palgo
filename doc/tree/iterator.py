'''
Created on Feb 12, 2015
accepted
@author: Shaun

idea --> in order traversal of BST  left node then right
while accepted, it is to the slower end of the pack

'''
# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class BSTIterator:
    # @param root, a binary search tree's root node
    
    def __init__(self, root):
        self.stack = []
        self.pushLeft(root)
        
    def pushLeft(self,node):
        while node:
            self.stack.append(node)
            node = node.left
        
    # @return a boolean, whether we have a next smallest number
    def hasNext(self):
        return len(self.stack) > 0

    # @return an integer, the next smallest number
    def next(self):
        node = self.stack.pop()
        self.pushLeft(node.right)
        return node.val

# Your BSTIterator will be called like this:
# i, v = BSTIterator(root), []
# while i.hasNext(): v.append(i.next())