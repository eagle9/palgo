#adapted from jiadai c++, Your submission beats 69.11% Submissions!
#not yet fully understand
class Solution:
    ''' 
     * @param n an integer that is the number of nodes(0 to n-1) in a graph
     * @param edges a list of undirected edges
     * @return true if it's a valid tree, or false
    ''' 
    def validTree(self, n, edges):
        # write your code here

        if n == 0:
            return True

        if len(edges) != n - 1:
            return False

        #vector<int> parent(n);
        parent = [i for i in range(n)]

        for edge in edges:
            x = edge[0]
            y = edge[1]
            xp = self.findParent(parent, x)
            yp = self.findParent(parent, y)
            if xp == yp:
                return False #why? makes sense now since x & y connected, if they has same parent, then there is a cycle
            parent[xp] = yp #  x---y--xp--yp
        return True

    def findParent(self,parent, n):
        while parent[n] != n:
            parent[n] = parent[parent[n]]
            n = parent[n]
        return n
