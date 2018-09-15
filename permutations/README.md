15. Permutations
Description
Given a list of numbers, return all possible permutations.

You can assume that there is no duplicate numbers in the list.

Example
For nums = [1,2,3], the permutations are:

[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
Challenge
Do it without recursion.

Difficulty: medium
Com: MS, Linkedin

Idea similiar to string permutations ii 
sort, then use next permutation to find all permutations
this algorithm does not use recursion

recursion is slower, check jiadai's, found that it is not easy to understand
