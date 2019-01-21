221. Maximal Square
Medium
Share
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example:

Input: 

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output: 4

Topic: dp
Similar: maximal rectangle, largest plus sign

I like grandyang idea3 dp

   [dp i-1 j-1]  [dp i-1 j]
   [dp i   j-1]  [dp i  j ]
  it is easy to see dp[i][j] = min(dp[i-1][j-1],dp[i-1][j],dp[i][j-1] + 1
