#based on jz java version 1: BFS, Your submission beats 49.80% Submissions!
#Your submission beats 85.16% Submissions!
class Solution:
    '''
     * @param n an integer
     * @param edges a list of undirected edges
     * @return true if it's a valid tree, or false
    '''
    def validTree(self,n, edges):
        if n == 0:
            return False

        if len(edges) != n - 1:
            return False

        graph = self.initializeGraph(n, edges)

        #bfs
        Q = [0]
        visited = set() 
        visited.add(0)
        while Q:
            node = Q.pop(0)
            for neighbor in graph[node]:
                if neighbor in visited:
                    continue
                visited.add(neighbor)
                Q.append(neighbor)

        return len(visited) == n #makes sense, all n nodes are visited

    def initializeGraph(self,n, edges):
        graph = {}
        for i in range(n):
            graph[i] = set()

        for [u,v] in  edges:
            graph[u].add(v)
            graph[v].add(u)

        return graph
