# 539. Move Zeroes

Difficulty:easy, com: facebook, bloomberg 

http://www.lintcode.com/en/problem/move-zeroes/

Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

**Notice**  

1. You must do this in-place without making a copy of the array.
2. Minimize the total number of operations.

**Example**  
Given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

go over the array and check non zero of each element
use indexNonZ to track index for non zero element
consider jz solution, but i have modified it for better understanding
consider jiadai's too. same idea.
