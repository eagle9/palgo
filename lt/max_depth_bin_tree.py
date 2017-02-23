# Definition for a binary tree node.
'''
no. 104 
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
'''
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    
    def maxDepth(self, root): #remember pass self to the member method
        """
        root type: TreeNode
        return type: int
        """
	#deal with boundary and exit conditions
        if root==None: return 0
        if root.left == None and root.right == None: return 1
        left=1
        right=1
        if root.left != None:
            left += self.maxDepth(root.left)  #self.maxDepth is for recursive member method call
        if root.right != None:
            right += self.maxDepth(root.right)
        return left if left>right else right
	# python expression for a>b?a:b in c++ or java
