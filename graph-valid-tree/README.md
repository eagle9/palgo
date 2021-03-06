261. Graph Valid Tree
Medium 661 20 Favorite Share

Given n nodes labeled from 0 to n-1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.

Example 1:
Input: n = 5, and edges = [[0,1], [0,2], [0,3], [1,4]]
Output: true

Example 2:
Input: n = 5, and edges = [[0,1], [1,2], [2,3], [1,3], [1,4]]
Output: false

Note: you can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0,1] is the same as [1,0] and thus will not appear together in edges.

0 ~ 6 months6 months ~ 1 year1 year ~ 2 years
Google | 3 LinkedIn | 2 Amazon | 2

Topics: Depth-first Search, Breadth-first Search,Union Find, Graph

Similar: 
Course Schedule,medium 
Number of connected component,medium
redundant connection, medium

Hint 1: Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], what should your return? Is this case a valid tree?
Hint 2: According to the definition of tree on Wikipedia: “a tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.”
