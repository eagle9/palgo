900. Closest Binary Search Tree Value
Description
Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.

Given target value is a floating point.
You are guaranteed to have only one unique value in the BST that is closest to the target.
Example
Given root = {1}, target = 4.428571, return 1.

Related Problems
closest binary search tree value

idea:
traverse the bst inorder, if target is <= node.val, then return the node.val
   if target > node.val, keep going until 
  1) last node of the bst, return node.val
  2) target <= node.val, immediately return node.val
