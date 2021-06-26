#based on jiadai c++ 
#Your submission beats 52.83% Submissions!
class Solution:
    ''' 
     @param root the root of binary tree
     @return a lists of linked list
    ''' 
    def binaryTreeToLists(self, root):
        #Write your code here
        result = []
        if root == None:
            return result
        Q = [root] #first level only see root
        while Q:
            qs = len(Q)
            node = Q.pop(0)
            head = ListNode(node.val) #create head with first node
            p = head #iterator
            if node.left:
                Q.append(node.left)
            if node.right:
                Q.append(node.right)
            for i in range(1, qs): #other nodes at this level
                node = Q.pop(0)
                p.next = ListNode(node.val)
                p = p.next;
                if node.left:
                    Q.append(node.left)
                if node.right:
                    Q.append(node.right)
            result.append(head)
        return result
