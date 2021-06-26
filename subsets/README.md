78. Subsets
Medium 3237 75 Add to List Share

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
Accepted 522,015 Submissions 881,433

LeetCode
0 ~ 6 months6 months ~ 1 year1 year ~ 2 years

Facebook | 10 Amazon | 8 Google | 4 Bloomberg | 3 Microsoft | 2 Goldman Sachs | 2 Atlassian | 2

Subsets II Medium 
Generalized Abbreviation Medium
Letter Case Permutation
Easy

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

