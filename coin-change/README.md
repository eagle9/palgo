322. Coin Change
Medium

You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:

Input: coins = [1, 2, 5], amount = 11
Output: 3 
Explanation: 11 = 5 + 5 + 1

Example 2:
Input: coins = [2], amount = 3
Output: -1

Note:
You may assume that you have an infinite number of each kind of coin.

0 ~ 6 months6 months ~ 1 year1 year ~ 2 years
JPMorgan | 20 Amazon | 15 LinkedIn | 9 Capital One | 9 Microsoft | 6 Google | 5 Bloomberg | 4 Airbnb | 3 VMware | 2 Facebook | 2 Goldman Sachs | 2 Visa | 2 Hulu | 2

Topic: Dynamic Programming

idea: 
with small problem, 
[1,2,5] 11
[1] 11   11 1 coins
[1,2] to make 11
introduce 2d dp[i, j] i coins 0- i, j target?
this is right direction. but i kind of give up. 

way1:   [1] to make 11,   dp[0] = 11
way2:  use coin[1] only, 11 is 2's multiple?   contribue 0
	   use coin[1] and coin[0], 

[1,2] 11-5*2 = 1,    [1] 1  min(6, 11)
[1,2,5] 11    [1,2] 11-5*2 = 1
dp[i] min number of coins [0..i] to make target
dp[i+1] add 1 coin,  not use coin i+1,   dp[i] to make target
 use coins[i+1] 
no clean way go from small problem to big
