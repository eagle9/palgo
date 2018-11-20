943. Range Sum Query - Immutable
Description
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

You may assume that the array does not change.
There are many calls to sumRange function.
Straightforward solution, O(j-i)
But can be O(1) if we populate prefix sum beforehand.  Assume array nums is immutable.
Example
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
Related Problems
range sum query - mutable, range sum query 2d -mutable
range sum query 2d - immutable
