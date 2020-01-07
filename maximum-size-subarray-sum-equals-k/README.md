325. Maximum Size Subarray Sum Equals k
Medium 712 27 Favorite Share

Given an array nums and a target value k, find the maximum length of a subarray that sums to k. If there isn't one, return 0 instead.

Note:
The sum of the entire nums array is guaranteed to fit within the 32-bit signed integer range.

Example 1:

Input: nums = [1, -1, 5, -2, 3], k = 3
Output: 4 
Explanation: The subarray [1, -1, 5, -2] sums to 3 and is the longest.
Example 2:

Input: nums = [-2, -1, 2, 1], k = 1
Output: 2 
Explanation: The subarray [-1, 2] sums to 1 and is the longest.
Follow Up:
Can you do it in O(n) time?

Accepted 89K
Submissions 194.3K

0 ~ 6 months6 months ~ 1 year1 year ~ 2 years
Facebook | 3 Google | 3

Similar:
Minimum Size Subarray Sum Medium
Range Sum Query - Immutable Easy
Contiguous Array Medium
Subarray Product Less Than K Medium

Hint 1
Try to compute a sum of a subsequence very fast, i.e in O(1) … Think of prefix sum array.
Hint 2
Given S[i] a partial sum that starts at position 0 and ends at i, what can S[i - k] tell you ?

Hint 3
Use HashMap + prefix sum array.

Topic: Hash Table
