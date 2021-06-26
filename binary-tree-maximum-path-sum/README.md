124. Binary Tree Maximum Path Sum
Hard 1746 132 Favorite Share

Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

Example 1:
Input: [1,2,3]
       1
      / \
     2   3
Output: 6

Example 2:
Input: [-10,9,20,null,null,15,7]
   -10
   / \
  9  20
    /  \
   15   7
Output: 42
Accepted 204,925
Submissions 673,917

Contributor LeetCode
0 ~ 6 months6 months ~ 1 year1 year ~ 2 years
Facebook | 26 Amazon | 23 Google | 11 Microsoft | 2

Similar:
Path Sum Easy
Sum Root to Leaf Numbers Medium
Path Sum IV Medium
Longest Univalue Path Easy

idea forming:
path: parth child relation 
enumerate all paths, for each node of the tree, consider all paths that go through the node
for each node, path left of the node,max sum,  path right of the node, max sum, combine
int leftSum (TreeNode root) {
	//return max sum from the root going down from its left,   max sum from the root going down from its right
	if (root == NULL) return 0;
 	int sum = leftSum(root->left);
	return max(sum + root-val, root->val); 	
int rightSum (TreeNode root) {
	//return max sum from the root going down from its right

max path sum via node  =  leftSum +  rightSum - node.val   
use a global variable to track the maxPathSum

}
far from the a good solution. 

wrong answer

hua ---> cutting angle
int helper(TreeNode * root)
//return max path sum from root, going down from left, or right
//root must be included
