652. Find Duplicate Subtrees
Medium

Given a binary tree, return all duplicate subtrees. For each kind of duplicate subtrees, you only need to return the root node of any one of them.

Two trees are duplicate if they have the same structure with same node values.
Example 1:
        1
       / \
      2   3
     /   / \
    4   2   4
       /
      4
The following are two duplicate subtrees:
      2
     /
    4
and
    4
Therefore, you need to return above trees' root in the form of a list.

0 ~ 6 months6 months ~ 1 year1 year ~ 2 years

Uber | 3 Microsoft | 3 Google | 2 Lyft | 2

Similar:
Serialize and Deserialize Binary Tree Hard
Serialize and Deserialize BST Medium
Construct String from Binary Tree Easy

idea:
binary tree, traverse the binary tree, find the list of node
any two nodes of the list as root1 and root2, check if they are duplicate
enter root1 into result set 
root1 root2 duplicate, root1 root3 duplicate, only root1 entered, how???
   root2 root3 duplicate
another idea,   serialize bt given by a root to string
traverse the binary tree, at each node, serialize binary tree root as this node
we will get a list of string

4   24  4 24 4  3244  1234#244
easy to see 3 4s and 2 24s
