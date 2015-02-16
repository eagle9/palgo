'''
Created on Dec 31, 2014

@author: XY1267
   1
    \
     2
    /
   3
'''
#Definition for a  binary tree node
class TreeNode1:
    def __init__(self, x):
        self.val = x
        self.__val2 = x
        self.left = None
        self.right = None
    def getVal2(self):
        return self.__val2


# @param root, a tree node
# @return a list of integers
class Solution:
    def preorderTraversal(self,root):
        visited = set()
        stack = [root]
        while stack:
            n = stack.pop()
            #visit n
            yield n.val
            if n.right is not None and n.right not in visited: stack.append(n.right)
            if n.left is not None and n.left not in visited: stack.append(n.left)
    def isBalanced(self,root):
        return abs(self.maxHeight(root) - self.minHeight(root)) <=1
    
    #@ return max height from root to leaves
    def maxHeight(self,root):
        if root == None: 
            return 0
        return max(self.maxHeight(root.left), self.maxHeight(root.right)) + 1
    
    def minHeight(self,root):
        if root == None: 
            return 0
        return min(self.minHeight(root.left), self.minHeight(root.right)) + 1
           
    def createTree(self,list,start,end):
        if (start > end ): return None
        mid = (start + end)/2
        root = TreeNode1(mid)
        root.left = self.createTree(list,start,mid-1)
        root.right= self.createTree(list, mid+1, end)
        return root
        

n = {}
for i in range(1,4):
    n[i] = TreeNode1(i)
for i in range(1,4):
    print n[i].val

n[1].right = n[2]
n[2].left = n[3]
sol = Solution()
print list(sol.preorderTraversal(n[1]))


aa = [
      [1,2,2,3,3,3,3,4,4,4,4,4,4,None,None,5,5],
      [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
      ]

for x in aa:
    root = sol.createTree(x, 0, len(x)-1)
    #print 'root.left.val2=',root.left.__val2
    print 'root.left.val2=',root.left.getVal2()
    print x, "is balanced?", sol.isBalanced(root)


