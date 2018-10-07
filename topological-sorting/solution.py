"""
Definition for a Directed graph node
class DirectedGraphNode:
    def __init__(self, x):
        self.label = x
        self.neighbors = []
"""
#adapted from jiadai c++
#Your submission beats 55.60% Submissions!

class Solution:
    def topSort(self,graph):
        # write your code here
        result = []
        degrees = {}
        for node in graph:
            if node not in degrees:
                degrees[node] = 0
            for neighbor in node.neighbors:
                if neighbor in degrees:
                    degrees[neighbor] += 1
                else:
                    degrees[neighbor] = 1

        Q = []
        for node in degrees:
            if degrees[node] == 0:
                Q.append(node)

        while Q:
            node = Q.pop(0)
            result.append(node)
            
            for neighbor in node.neighbors:
                degrees[neighbor] -= 1
                if degrees[neighbor] == 0:
                    Q.append(neighbor)

        return result
