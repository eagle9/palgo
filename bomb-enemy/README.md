361. Bomb Enemy
Medium
30%
Given a 2D grid, each cell is either a wall 'W', an enemy 'E' or empty '0' (the number zero), return the maximum enemies you can kill using one bomb.
The bomb kills all the enemies in the same row and column from the planted point until it hits the wall since the wall is too strong to be destroyed.
Note: You can only put the bomb at an empty cell.

Example:

Input: [["0","E","0","0"],["E","0","W","E"],["0","E","0","0"]]
Output: 3 
Explanation: For the given grid,

0 E 0 0 
E 0 W E 
0 E 0 0

Placing a bomb at (1,1) kills 3 enemies.

0 ~ 6 months6 months ~ 1 year1 year ~ 2 years
Google | 4 Uber | 2 

idea:
brute force
from each 0 empty, go left, right, up and down, till border or W, count how many Es, record res = max(res,count)
time O(n^3)
or dp
for each row, from left to right
 from left to i, dp[i] number of Es seen till W or border
for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
		  if  g[r][i] == 0 
			 f[r][j] = f[r][j-1]
		  else g[r][i] == 'E'
			 count++;
			 f[r][j] = f[r][j-1]+1
		  else // == W
			 f[r][j] == 0
		}
		for(int j = n-1; j >=1; --j) {
			if g[r][j-1] == '0'
				f[r][j-1] = f[r][j];
		}
}
similar algorithm for g, for each column, down and up
int res = 0
for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
		if gij == '0' {
			res = max(res, f[ij] + g[ij]);
		}
	}
}
return res;

count e for row
0 E 0 0  1 1 1 1
E 0 W E  1 1 0 1
0 E 0 0  1 1 1 1
count e for col
1 2 0 1 
1 2 0 1 
1 2 0 1
not sure about its correctness
other idea???
tried to go deeper and improve, with correctness verification on mind
finished my idea, proud of myself, debug with 2 leetcode test cases, finally accepted
March 22 2019
