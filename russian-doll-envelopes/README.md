354. Russian Doll Envelopes
Hard
You have a number of envelopes with widths and heights given as a pair of integers (w, h). One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.

What is the maximum number of envelopes can you Russian doll? (put one inside other)

Note:
Rotation is not allowed.

Example:
Input: [[5,4],[6,4],[6,7],[2,3]]
Output: 3 
Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).

Companies: Google | 3 

Similar: Longest Increasing Subsequence Medium


Topic: Binary Search, Dynamic Programming

idea: 
  find the max envelop
	now i understand a inside b and b inside c
   sort the envolopes by comparsion, by width
	0       1     2      3
   [2,3]   [5,4] [6,4]  [6,7]
   dp[i] russian envelop number from 0 to i
   idx[i]   max r envelop last envelop index
   dp[0] = 1, idx[0] = 0
   dp[1]  e0 inside e1?  yes  dp[0] + 1 = 2, idx[1] = 1
	dp[2]: e0 inside e2? yes  2, 2,
		  e1 inside e2? no  2, i = 1
          max is dp[2] = max(2,2)=2, i = 1,2
dp[3]
   e0 inside e3,  2, i=3
   e1 inside e3,  3, i=3 
	e2 inside e3, no, 2, i=2,2

time nlogn + O(n^2)
          
  
