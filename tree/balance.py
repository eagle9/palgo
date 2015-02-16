'''
Created on Feb 13, 2015

@author: Shaun
'''
class Solution:
    def isBalanced(self,root):
    
        if root == None: return True
        val = self.getBalance(root)
        if val ==-1:  return False
        return True
    def getBalance(self,node):
        if node == None: return 0;
        left = self.getBalance(node.left)
        if left == -1: return -1
        right = self.getBalance(node.right)
        if right == -1: return -1
        if left-right>1 or right-left>1:
            return -1
        return left+1 if left>right else right+1