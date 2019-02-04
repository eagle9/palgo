562. Longest Line of Consecutive One in Matrix
Medium
Given a 01 matrix M, find the longest line of consecutive one in the matrix. The line could be horizontal, vertical, diagonal or anti-diagonal.
Example:
Input:
[[0,1,1,0],
 [0,1,1,0],
 [0,0,0,1]]
Output: 3
Hint: The number of elements in the given matrix will not exceed 10,000.
Topic: Array
Hint 1:
One solution is to count ones in each direction separately and find the longest line. Don't you think it will take too much lines of code?
Hint 2:
Is it possible to use some extra space to make the solution simple?
Hint 3:
Can we use dynamic programming to make use of intermediate results?
Hint 4:
Think of a 3D array which can be used to store the longest line obtained so far for each direction.

