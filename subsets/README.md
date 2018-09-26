17. Subsets, lintcode
Description
Given a set of distinct integers, return all possible subsets.

Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
Example
If S = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

Challenge
Can you do it in both recursively and iteratively?

iterative way use 1-2^n binary number representation
recursive way use dfs or bfs
each subset requires that its elements in non-descending order, so the input array will be sorted
