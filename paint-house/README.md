256. Paint House
Easy
15%
There are a row of n houses, each house can be painted with one of the three colors: red, blue or green. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a n x 3 cost matrix. For example, costs[0][0] is the cost of painting house 0 with color red; costs[1][2] is the cost of painting house 1 with color green, and so on... Find the minimum cost to paint all houses.

Note:
All costs are positive integers.

Example:
         r  b  g  
Input: [[17,2,17]   h0
		[16,16,5],  h1
		[14,3,19]]  h2
Output: 10
Explanation: Paint house 0 into blue, paint house 1 into green, paint house 2 into blue. 
             Minimum cost: 2 + 5 + 3 = 10.
idea:
         r  b  g  
Input: [[17,2,17]   h0
		[16,16,5],  h1
		[14,3,19]]  h2
key point:   no 2 adj houses same color, min cost to paint all
      r             b   g    <--min cost of using color to hi    ans  = min
h0    17            2   17                                        2 
h1    16+min(2,7)   16+min(17,17)    5 + min(2,17)                7 
h2    14+min(33,7)  3+min(18,7)      19+min(18,33)                10

0 ~ 6 months6 months ~ 1 year1 year ~ 2 years
LinkedIn | 5
House Robber Easy
House Robber II Medium
Paint House II Hard
Paint Fence Easy

515. Paint House
Description
There are a row of n houses, each house can be painted with one of the three colors: red, blue or green. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a n x 3 cost matrix. For example, costs[0][0] is the cost of painting house 0 with color red; costs[1][2] is the cost of painting house 1 with color green, and so on... Find the minimum cost to paint all houses.

All costs are positive integers.

Have you met this question in a real interview?  
Example
Given costs = [[14,2,11],[11,14,5],[14,3,10]] return 10

house 0 is blue, house 1 is green, house 2 is blue, 2 + 5 + 3 = 10

Related Problems
Product of Array Except Self, House Robber, House Robber II, 
paint fence,paint house II
Company: Linkedin
Difficulty: Medium
