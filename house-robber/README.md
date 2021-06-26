198. House Robber
Easy 2678 85 Favorite Share

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
             Total amount you can rob = 2 + 9 + 1 = 12.

Topic: Dynamic Programming 
Similar: 
Maximum Product Subarray, Medium
House Robber II, Medium
Paint House, Easy
Paint Fence, Easy
House Robber III, Medium
Non-negative Integers without Consecutive Ones Hard
Coin Path, Hard
Delete and Earn, Medium

idea: 
input array of numbers
take number out of, no adjacent numbers, max the sum
A[i] max money taken from 0 to house i, cash at i taken
B[i] max money from 0 to i, cash at i not taken
A[i] = max(A[i-1], B[i-1]+a[i]) 
B[i] = max(A[i-1], B[i-1])
another idea
 i-2     i-1    i
dp[i]  taken  dp[i-2]
       not taen dp[i-1]
