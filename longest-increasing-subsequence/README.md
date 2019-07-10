300. Longest Increasing Subsequence
Medium 2648 60 Favorite Share 

Given an unsorted array of integers, find the length of longest increasing subsequence.

Example:
Input: [10,9,2,5,3,7,101,18]
Output: 4 
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 
Note:
There may be more than one LIS combination, it is only necessary for you to return the length.
Your algorithm should run in O(n2) complexity.
Follow up: Could you improve it to O(n log n) time complexity?

Companies:
0 ~ 6 months6 months ~ 1 year1 year ~ 2 years
Amazon | 9 Google | 6 Microsoft | 6 Facebook | 3

Similar: 
Increasing Triplet Subsequence Medium
Russian Doll Envelopes Hard
Maximum Length of Pair Chain Medium
Number of Longest Increasing Subsequence Medium
Minimum ASCII Delete Sum for Two Strings Medium

high freq problem with many similar problems, must do well
dp

Topic: Binary Search, Dynamic Programming
idea: 
dp angle: dp[i] LIS from 0 to i, for d[i+1],  dp[i+1] = max (dp[k]+1), k = 0...i, if nums[i+1] > nums[k]
time O(n^2)

binary search angle: 

find first element in dp that is >= cur
[]
[10], cur = 10
[9], cur = 9

update makes sure following action correct
input: [0, 8, 4, 12, 2]
dp: []
dp: [0], cur = 0
dp: [0, 8], cur = 8, not found >=, push_back
dp: [0, 4], cur=4, found 8, update
dp: [0, 4, 12], cur=12, not found, push_back
dp: [0,2,12], cur=2, found 4, update 4
