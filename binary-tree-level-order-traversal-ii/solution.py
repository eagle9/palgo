class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None

class Solution:
    """
    @param root: A tree
    @return: buttom-up level order a list of lists of integer
    """
    #Your submission beats 84.05% Submissions!
    #based jiadia c++
    
    def levelOrderBottom(self, root):
        # write your code here

        result = []
        if root == None:
            return result
        Q = [root]
        while Q:
            n = len(Q)
            path = []
            for i in range(n):
                p = Q.pop(0)
                path.append(p.val)
                if p.left:
                    Q.append(p.left)
                if p.right:
                    Q.append(p.right)
            result.append(path)
        result.reverse()
        return result
