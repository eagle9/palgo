'''
Created on Feb 5, 2015

@author: XY1267
sum-root-to-leaf-numbers/

'''
#Definition for a  binary tree node
class TreeNode1:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    # @param root, a tree node
    # @return an integer
    
    
    def __init__(self):
        self.paths = []
    
    def sumNumbers(self):
        
        total = 0
        for path in self.paths:
            total += self.path2Number(path)
        return total
    
    
    def traverse(self,root,path):
        if root is None: return
        path.append(root)
        if root.right is None and root.left is None:
            print path
            #yield path
            self.paths.append(path)
        else:
            self.traverse(root.left, [n for n in path])   
            self.traverse(root.right,[n for n in path])
            
        
    def path2Number(self,path): 
        number = 0
        for i,v in enumerate(reversed(path)):
            #print v.val
            number += v.val * 10**i
        return number
    
if __name__ == '__main__':
    node1 = TreeNode1(1)       
    node2 = TreeNode1(2)
    node3 = TreeNode1(3)
    node4 = TreeNode1(4)
    node5 = TreeNode1(5)
    node1.left  = node2
    node1.right = node3
    node2.left = node4
    node2.right  = node5
    s = Solution()
    s.traverse(node1,[])
    
    for p in s.paths:
        print [n.val for n in p]
    res = s.sumNumbers()
    print 124 + 125 + 13 == res

    
    