#adapted from jiadai c++, Your submission beats 100.00% Submissions!
class Solution:
    """
    @param root: a TreeNode, the root of the binary tree
    @return: nothing
    """
    def invertBinaryTree(self,root):
        # write your code here
        if root == None:
            return

        self.invertBinaryTree(root.left)
        self.invertBinaryTree(root.right)
        left = root.left
        root.left = root.right
        root.right = left
