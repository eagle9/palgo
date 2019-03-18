78. Subsets
Medium
40%
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
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

Companies: Facebook | 8 Amazon | 5 Uber | 5 Goldman Sachs | 4 Yahoo | 3 Adobe | 2 Apple | 2 Google | 2 Lyft | 2 Bloomberg | 2 LinkedIn | 2 Walmart Labs | 2

Similar:
Subsets II Medium
Generalized Abbreviation Medium
Letter Case Permutation Easy

Topic: Array, Backtracking, Bit Manipulation

idea: 
input: nums vector<int>
output: vector<vector<int>> each vector int from small to large
helper(nums,left, right)
for each i : nums
	//  0..i-1    i  i+1 .. n-1
	left_set = helper(i-1)
	right_set = helper(n-i-1)
	for (left: left_set) 
		for (right: right_set)
			res.push_back(left + i + right) //use i
			res.push_back(left + right) //not use i
return res
not clean, is your idea correct? test with simple case!!!!

