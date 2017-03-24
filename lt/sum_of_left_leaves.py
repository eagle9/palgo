# Time:  O(n)
# Space: O(h)

# Find the sum of all left leaves in a given binary tree.
#
# Example:
#
#     3
#   / \
#   9  20
#     /  \
#   15   7
#
# There are two left leaves in the binary tree,
# with values 9 and 15 respectively. Return 24.

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def sumOfLeftLeaves(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        def sumOfLeftLeavesHelper(root, is_left):
            if not root:
                return 0
            if not root.left and not root.right:
                return root.val if is_left else 0
            return sumOfLeftLeavesHelper(root.left, True) + \
                   sumOfLeftLeavesHelper(root.right, False)
        
        return sumOfLeftLeavesHelper(root, False)

#recursion properly used can produce very simple  solutions
#make sure your recusion can exit properly
#why need a helper function? because deeper call needs to know  root is a left or right child
class Solution2(object): #i like to use root == None rather than not root
    def sumOfLeftLeaves(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        def sumOfLeftLeavesHelper(root, is_left):
            if root == None:
                return 0
            if root.left == None and root.right == None:
                return root.val if is_left else 0
            return sumOfLeftLeavesHelper(root.left, True) + \
                   sumOfLeftLeavesHelper(root.right, False)
        
        return sumOfLeftLeavesHelper(root, False)

class Solution3(object):
    def sumOfLeftLeaves(self,root):
        def helper(node,is_left):
            if node == None:
                return 0
            if node.left == None and node.right == None:#leaf node
                return node.val if is_left else 0   #
            return helper(node.left,True) + helper(node.right,False)
        return helper(root,False)

#TODO: any traversal of binary tree, if node is leaf and left child, contribute node.val to sum
class Solution4(object):
    def sumOfLeftLeaves(self,root):
        def preorder(node,is_left):
            if node == None:
                return 0
            if node.left == None and node.right==None: 
                return node.val  if is_left else  0
            return preorder(node.left,True) + preorder(node.right,False)
        return preorder(root, False)
'''
def inorder(tree):
  if tree != None:
      inorder(tree.getLeftChild())
      print(tree.getRootVal())
      inorder(tree.getRightChild())
'''
class Solution5(object):
    def sumOfLeftLeaves(self,root):                
        def inorder(node,is_left):
            if node == None:
                return 0
            else:
                sum_left = inorder(node.left,True)
                #visit the node: check node.val and make contribution to sum
                if node.left == None and node.right == None:
                    return node.val if is_left else 0 
                return sum_left + inorder(node.right,False)
        return inorder(root,False)

'''
def postorder(tree):
    if tree != None:
        postorder(tree.getLeftChild())
        postorder(tree.getRightChild())
        print(tree.getRootVal())
postorder is pretty slow compared to inorder or preorder
'''
class Solution6(object):
    def sumOfLeftLeaves(self,root):
        def postorder(node,is_left):
            if node == None:
                return 0
            else:
                if node.left != None or node.right != None:
                    return postorder(node.left,True) + postorder(node.right,False)
                else:
                    return node.val if is_left else 0 
        return postorder(root,False)
                    
