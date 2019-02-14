279. Perfect Squares
Medium
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

Example 1:
Input: n = 12
Output: 3 
Explanation: 12 = 4 + 4 + 4.

Example 2:
Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.

Topic: Math, Dynamic Programming, Breadth-first search
Similar: Count primes, ugly number ii

idea: 
given n, find the list of square numbers <=n
to make sum n with these number with repetition 
dp[i] the least number of perfect square number that adds to i. I came up the right dp on first try.
how to figure out recurrence??? give me some hint??

