Lintcode 578
medium
Description
Given the root and two nodes in a Binary Tree. Find the lowest common ancestor(LCA) of the two nodes.
The lowest common ancestor is the node with largest depth which is the ancestor of both nodes.
Return null if LCA does not exist.

node A or node B may not exist in tree.

Have you met this question in a real interview?  
Example
Example1

Input: 
{4, 3, 7, #, #, 5, 6}
3 5
5 6
6 7 
5 8
Output: 
4
7
7
null
Explanation:
  4
 / \
3   7
   / \
  5   6

LCA(3, 5) = 4
LCA(5, 6) = 7
LCA(6, 7) = 7
LCA(5, 8) = null

Example2

Input:
{1}
1 1
Output: 
1

Related Problems
Lowest common ancestor ii, longest common ancestor of binary tree
