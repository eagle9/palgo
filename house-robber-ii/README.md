213. House Robber II
Medium

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2),
             because they are adjacent houses.
Example 2:

Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.

Topic: DP

idea 
dp[0] =  nums[0], clarify 
dp[1] = max(nums[0], nums[1]) 
dp[2] = max(n0, n1, n2)
       dp[i] = max(nums[i] + dp[i-2], 0 + dp[i-1]) 
       if i == n-1
			if nums[0] taken, not take nums[i] 
			else nums[0] not taken, taken nums[i]
	   but how we know nums[0] take or not???

      i-2  i-1   i
                 
