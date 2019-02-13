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


#use generator to collect results
class Solution:
    # @param root, a tree node
    # @return an integer
    def sumNumbers(self,paths):
        
        total = 0
        for path in paths:
            total += self.path2Number(path)
        return total
    
    def traverse(self,root,path):
        if root is None: return
        path.append(root)
        if root.right is None and root.left is None:
            print path
            yield path
            
        else:
            self.traverse(root.left, [n for n in path])   
            self.traverse(root.right,[n for n in path])
            
        
    def path2Number(self,path): 
        number = 0
        for i,v in enumerate(reversed(path)):
            #print v.val
            number += v.val * 10**i
        return number
    def sample_gen(self):
        for i in range(10):
            yield [x for x in range(i)]
if __name__ == '__main__':
    s = Solution()
    g1 = s.sample_gen()
    
    print g1
    for i in g1:
        print i
    node1 = TreeNode1(1)       
    node2 = TreeNode1(2)
    node3 = TreeNode1(3)
    node4 = TreeNode1(4)
    node5 = TreeNode1(5)
    node1.left  = node2
    node1.right = node3
    node2.left = node4
    node2.right  = node5
    
    paths = s.traverse(node1,[])
    count = 0
    for p in paths:
        count += 1
        print [n.val for n in p]
    print "count=", count
    res = s.sumNumbers(paths)
    print 124 + 125 + 13 == res

    
    