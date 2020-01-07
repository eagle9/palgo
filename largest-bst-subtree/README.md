333. Largest BST Subtree
Medium 465 48 Favorite Share

Given a binary tree, find the largest subtree which is a Binary Search Tree (BST), where largest means subtree with largest number of nodes in it.

Note:
A subtree must include all of its descendants.

Example:

Input: [10,5,15,1,8,null,7]

   10 
   / \ 
  5  15 
 / \   \ 
1   8   7

Output: 3
Explanation: The Largest BST Subtree in this case is the highlighted one.
             The return value is the subtree's size, which is 3.
Follow up:
Can you figure out ways to solve it with O(n) time complexity?

Accepted
38K
Submissions
110.6K

0 ~ 6 months6 months ~ 1 year1 year ~ 2 years

Lyft | 3
Apple | 2
1 year ~ 2 years
Google

Topic: Tree

You can recursively use algorithm similar to 98. Validate Binary Search Tree at each node of the tree, which will result in O(nlogn) time complexity.
