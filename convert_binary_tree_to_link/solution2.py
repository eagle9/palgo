"""
Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        this.val = val
        this.left, this.right = None, None
Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None
"""
#adapted from jiadai c++ Your submission beats 52.83% Submissions! using list as Q
#Your submission beats 52.83% Submissions! when use collections.deque
#Your submission beats 37.11% Submissions! slower when use queue.Queue which synchronized
#tried 3 different types of queue implemenation in python, i would rather use list as queue. just be aware of other implemenations

from queue import Queue  #using synchronized Queue slower
from collections import deque
class Solution:
    # @param {TreeNode} root the root of binary tree
    # @return {ListNode[]} a lists of linked list
    '''
     @param root the root of binary tree
     @return a lists of linked list
    '''
    def binaryTreeToLists(self, root):
        #Write your code here
        result = []
        if root == None:
            return result
        #Q = [root] #first level only see root
        #Q = Queue()
        #Q.put(root)
        Q = deque([root])
        #while not Q.empty():
        while Q:
            qs = len(Q)
            #qs = Q.qsize()
            node = Q.popleft() #Q.pop(0)  #for list
            #node = Q.get()
            head = ListNode(node.val) #create head with first node
            p = head #iterator
            if node.left:
                Q.append(node.left)
                #Q.put(node.left)
            if node.right:
                Q.append(node.right)
                #Q.put(node.right)
            for i in range(1, qs): #other nodes at this level
                node = Q.popleft() #Q.pop(0) # for list as Q
                #node = Q.get()
                p.next = ListNode(node.val)
                p = p.next;
                if node.left:
                    Q.append(node.left)
                    #Q.put(node.left)
                if node.right:
                    Q.append(node.right)
                    #Q.put(node.right)
            result.append(head)
        return result
