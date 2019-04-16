lintcode 573. Build Post Office II
Description
English
Given a 2D grid, each cell is either a wall 2, an house 1 or empty 0 (the number zero, one, two), find a place to build a post office so that the sum of the distance from the post office to all the houses is smallest.

Return the smallest sum of distance. Return -1 if it is not possible.

You cannot pass through wall and house, but can pass through empty.
You only build post office on an empty.
Example 1:
Input:[ [0,1,0,0,0],
		[1,0,0,2,1],
		[0,1,0,0,0]]
Output: 8
Explanation: Placing a post office at (1,1), the distance that post office to all the house sum is smallest.
Example 2:

Input:[[0,1,0],[1,0,1],[0,1,0]]
Output:4
Explanation: Placing a post office at (1,1), the distance that post office to all the house sum is smallest.
Challenge
Solve this problem within O(n^3) time.

Related Problems
build post office,shortest distance from all buildings, walls and gates, zombie in a matrix 

companies: google

idea:  from each empty cell, bfs level by level, reaches a house,   sumDist += level, when all houses reached, you get one sumbDist, keep the minimum,  i,j -> nexti, nextj,   inbound, grid[ni][nj] can be 0 or 1 
