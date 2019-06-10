560. Subarray Sum Equals K
Medium

Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:
Input:nums = [1,1,1], k = 2
Output: 2
Note:
The length of the array is in range [1, 20,000].
The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].

0 ~ 6 months6 months ~ 1 year1 year ~ 2 years
Facebook | 40 Amazon | 12 Bloomberg | 8 Microsoft | 5 Apple | 4 Twilio | 3 Google | 2 Oracle | 2 Expedia | 2

Topic: Array, Hash Table
Two Sum Easy
Continuous Subarray Sum Medium
Subarray Product Less Than K Medium
Find Pivot Index Easy
Subarray Sums Divisible by K Medium

Hint 1
Will Brute force work here? Try to optimize it.
Hint 2
Can we optimize it by using some extra space?
Hint 3
What about storing sum frequencies in a hash table? Will it be useful?
Hint 4
sum(i,j)=sum(0,j)-sum(0,i), where sum(i,j) represents the sum of all the elements from index i to j-1. Can we use this property to optimize it.
