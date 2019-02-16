560. Subarray Sum Equals K
Medium
Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:
Input:nums = [1,1,1], k = 2
Output: 2
Note:
The length of the array is in range [1, 20,000].
The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].

Companies: a lot
topic: array, hash table
Similar: 
Two Sum
Easy
Continuous Subarray Sum Medium
Subarray Product Less Than K Medium
Find Pivot Index Easy
Hints:
Will Brute force work here? Try to optimize it.

Can we optimize it by using some extra space?

What about storing sum frequencies in a hash table? Will it be useful?

sum(i,j)=sum(0,j)-sum(0,i), where sum(i,j) represents the sum of all the elements from index i to j-1. Can we use this property to optimize it.
