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

shaun idea to use dp: 
with small problem, 
[1,2,5] 11
[1] 11   11 1 coins
[1,2] to make 11
introduce 2d dp[i, j] i coins 0- i, j target?  YES
what is range of i, and range of amount j?   j from 0 to target
i   from 0 coins to n coins, add 0 giving a good starting point, this is actually very key to clean up the idea. 
this is right direction. but i kind of give up 
the key is to come up with a table to figure out transition function

another key, consider coins being []
coin\amount
    0  1  2  3  4 5 6 7 8 9 10 11 
[]  0  mx mx ..............    mx     //mx is INT_MAX
1   0  1  2  ..................11   
2   0  
3   0
dp[i][j] =  min(dp[i][j],   dp[i][target-coins[i]+1 if target-coins[i] > 0 smaller = target - coins[i], else smaller =   
coin = 2,  dp[0] = 0, dp[2,1] = ? , d[2,2] = min(dp[2,2], dp[2,2-2] +1) = 1 
   dp[2,1], can not use coin2, use prev row d[1,1]  = 1 
   dp[2,3] =   min(--, dp[2,3-2]+1 = dp[2,1] + 1) 
each row, update # of coins to make amount, now we can just drow dp[i,j] to dp[j] 
way1:   [1] to make 11,   dp[0] = 11
way2:  use coin[1] only, 11 is 2's multiple?   contribue 0
	   use coin[1] and coin[0], 

[1,2] 11-5*2 = 1,    [1] 1  min(6, 11)
[1,2,5] 11    [1,2] 11-5*2 = 1
dp[i] min number of coins [0..i] to make target
dp[i+1] add 1 coin,  not use coin i+1,   dp[i] to make target
 use coins[i+1] 
no clean way go from small problem to big


idea to use search: 
    not hard to sort coins descending,  coins: [5,2,1], amount = 11
    coins, amount, used coins						    
                           [5,2,1], 11, 0
               / 2x5         | 1x5       \0x5
           [2,1],1,2    [2,1],6,1        [2,1],11,0     
          /          cut /3x2 cut\2x2 \1x2 
     [1],1,2+0   [1],0,4               [1],4,2
    /                               cut/1x4
 [], 0, 2+1

jz recursion is a good start  too, how you reduce the problem? then it is not hard to come up with recursion
