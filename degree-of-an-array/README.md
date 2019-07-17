697. Degree of an Array
Easy 529 468 Favorite Share

Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.

Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.

Example 1:
Input: [1, 2, 2, 3, 1]
Output: 2
Explanation: 
The input array has a degree of 2 because both elements 1 and 2 appear twice.
Of the subarrays that have the same degree:
[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
The shortest length is 2. So return 2.

Example 2:
Input: [1,2,2,3,1,4,2]
Output: 6

Note:
nums.length will be between 1 and 50,000.
nums[i] will be an integer between 0 and 49,999.

Accepted 52,986
Submissions 104,258

Contributor fishercoder
0 ~ 6 months6 months ~ 1 year1 year ~ 2 years
VMware | 2
6 months ~ 1 year1 year ~ 2 years
Mathworks | 5 IXL | 3 Walmart Labs | 3 Visa | 2 Robinhood | 2

Topic: Array

Similar:
Maximum Subarray Easy

Hint 1:
Say 5 is the only element that occurs the most number of times - for example, nums = [1, 5, 2, 3, 5, 4, 5, 6]. What is the answer?
