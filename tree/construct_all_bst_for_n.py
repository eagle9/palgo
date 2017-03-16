#http://www.geeksforgeeks.org/construct-all-possible-bsts-for-keys-1-to-n/
#A python prgroam to contrcut all unique BSTs for keys from 1 to n
#translated from the c++ program version
'''
For N = 3, there are 5 possible BSTs
  1              3        3         2      1
    \           /        /        /  \      \
     3        2         1        1    3      2
    /       /            \                    \
   2      1               2                    3
'''
import sys
'''object is a (global) variable. By default it is bound to a built-in class which is the root of the type hierarchy.

Always use self.x to access the instance attribute x. Note that unlike this in C++, self is not a keyword, though. You could give the first parameter of your method any name you want, but you are strongly advised to stick to the convention of calling it self.'''

class TreeNode(object):
    def __init__(self,x):
        self.key = x
        self.left = None
        self.right = None
def preorder(root):
    if (root != None):
        sys.stdout.write('%d - ' % root.key)
        preorder(root.left)
        preorder(root.right)
def constructTrees(start,end):
    res = []
    if start > end:
        res.append(None)
        return res
    for i in range(start,end+1):
        leftSubTree = constructTrees(start,i-1)
        rightSubTree= constructTrees(i+1,end)
        for j in range(len(leftSubTree)):
            left = leftSubTree[j]
            for k in range(len(rightSubTree)):
                right = rightSubTree[k]
                node = TreeNode(i)
                node.left,node.right = left,right
                res.append(node)
    return res

totalTreesFrom1toN = constructTrees(1,3)
print "Preorder traversals of all constructed BSTs are"
for i in range(len(totalTreesFrom1toN)):
    preorder(totalTreesFrom1toN[i])
    print ''

