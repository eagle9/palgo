"""
Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None
"""
"""
Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None
"""
#Your submission beats 67.40% Submissions!
class Solution:
    def serialize(self,root):
        # write your code here
        if root == None:
            return "{}"
        Q = [root]
        i = 0
        while i < len(Q):
            #for (int i = 0; i < Q.size(); ++i) {
            node = Q[i]
            if node != None:
                Q.append(node.left)
                Q.append(node.right)
            i+=1
        #while (Q.back() == nullptr) {
            #Q.pop_back();
        #}
        while Q[-1] == None:
            Q.pop()

        s = "{%d" % Q[0].val
        for i in range(1,len(Q)):
            if Q[i] == None:
                s += ",#";
            else:
                s += ",%d" % Q[i].val
        s += "}"
        return s
        
    def deserialize(self,data):
        # write your code here
        if data == "{}":
            return None

        #vector<string> s = split(data.substr(1, data.size() - 2), ",");
        s = data[1: -1].split(",")
        root = TreeNode(int(s[0]))
        Q = [root]
        leftChild = True
        index = 0
        #for (int i = 1; i < s.size(); ++i)
        for i in range(1,len(s)):
            if s[i] != "#":
                node = TreeNode(int(s[i]))
                if leftChild:
                    Q[index].left = node
                else:
                    Q[index].right = node
                Q.append(node)
            

            if not leftChild:
                index +=1

            leftChild = not leftChild

        return root
