"""
Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None
"""
#adapted from jiadai c++
#Your submission beats 99.64% Submissions!
class Solution:
    """
    @param root: A Tree
    @return: A list of lists of integer include the zigzag level order traversal of its nodes' values.
    """
    def zigzagLevelOrder(self,root):
        #write your code here
        result = []
        if root == None:
            return result

        Q = [root]
        fromLeft = True
        while Q:
            qs = len(Q)
            path = [None for i in range(qs)]
            #does not work if path = [] then use path.insert(node,index)
            for i in range(qs):
                node = Q.pop(0)
                index = i if fromLeft else qs - 1 - i
                #path.insert(index,node.val)
                path[index] = node.val
                if node.left:
                    Q.append(node.left)
                if node.right:
                    Q.append(node.right)

            fromLeft = not fromLeft  #done with this level, alternate direction
            result.append(path)

        return result
