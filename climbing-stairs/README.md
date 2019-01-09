111. Climbing Stairs
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example
Given an example n=3 , 1+1+1=2+1=1+2=3

return 3

Difficulty: easy
com: apple, adobe, fruquently 
dynamic programming, from buttom up, solve bigger with smaller, but beware of repeating sub problems
also be careful with starting numbers
https://algorithm.yuanbin.me/zh-hans/dynamic_programming/climbing_stairs.html
70. Climbing Stairs
Easy
You are climbing a stair case. It takes n steps to reach to the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
Note: Given n will be a positive integer.
Example 1:
Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
Topic: dp
Similar: min cost climbing stairs, fibonacci number
Hint: To reach nth step, what could have been your previous steps? (Think about the step sizes)
