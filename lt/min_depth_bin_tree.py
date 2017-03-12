# Definition for a binary tree node.
class TreeNode(object):
     def __init__(self, x):
         self.val = x
         self.left = None
         self.right = None

'''Solution1 use recursive call,  Your runtime beats 59.80% of python submissions.
Solution2 use level order traversal, when use the efficient collections.deque, beats about 89% python submissions

modified from http://www.geeksforgeeks.org/find-minimum-depth-of-a-binary-tree/
todo: study binary tree traversal
'''

class Solution1(object):
    def minDepth(self,root):
        """
        :type root: TreeNode
        :rtype: int
        """
        # Corner Case.Should never be hit unless the code is 
        # called on root = NULL
        if root is None:
            return 0
         
        # Base Case : Leaf node.This acoounts for height = 1
        if root.left is None and root.right is None:
            return 1
         
        # If left subtree is Null, recur for right subtree
        if root.left is None:
            return self.minDepth(root.right)+1
         
        # If right subtree is Null , recur for left subtree
        if root.right is None:
            return self.minDepth(root.left) +1
         
        return min(self.minDepth(root.left), self.minDepth(root.right))+1

class Solution2(object):
    def minDepth(self,root):
        """
        :type root: TreeNode
        :rtype: int
        """
        # Corner Case
        if root is None:
             return 0
     
        # Create an empty queue for level order traversal
        #q = []
        q = collections.deque() 
        # Enqueue root and initialize depth as 1
        q.append({'node': root , 'depth' : 1})
     
        # Do level order traversal
        while(len(q)>0):
        
            # Remove the front queue item
            #queueItem = q.pop(0)
            queueItem = q.popleft()
         
            # Get details of the removed item
            node = queueItem['node']
            depth = queueItem['depth']
            # If this is the first leaf node seen so far
            # then return its depth as answer
            if node.left is None and node.right is None:    
                return depth 
             
            # If left subtree is not None, add it to queue
            if node.left is not None:
                q.append({'node' : node.left , 'depth' : depth+1})
     
            # if right subtree is not None, add it to queue
            if node.right is not None:  
                q.append({'node': node.right , 'depth' : depth+1})    
