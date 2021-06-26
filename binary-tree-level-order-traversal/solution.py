"""
Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None
"""
import queue  #python3 synchronized queue
class Solution:
    """
    @param root: A Tree
    @return: Level order a list of lists of integer
    """
    #Your submission beats 78.40% Submissions!
    #Your submission beats 40.60% Submissions!
    #based on jiadai c++
    #use python list as a queue, enter queue list1.append, deque list1.pop(0)
    def levelOrder(self, root):
        # write your code here
        result = []
        if root == None:
            return result
        q = [root]
        #q = queue.Queue()
        #q.put(root)
        while q: #queue not empty
        #while not q.empty():
            n = len(q)
            #n = q.qsize()
            path = []
            for i in range(n):
                
                p = q.pop(0)
                #p = q.get()
                path.append(p.val)
                if p.left:
                    q.append(p.left)
                    #q.put(p.left)
                if p.right:
                    q.append(p.right)
                    #q.put(p.right)
                
            result.append(path)
        return result

