356. Line Reflection
Medium 104 280 Favorite Share

Given n points on a 2D plane, find if there is such a line parallel to y-axis that reflect the given points.

Example 1:
Input: [[1,1],[-1,1]]
Output: true

Example 2:
Input: [[1,1],[-1,-1]]
Output: false
Follow up:
Could you do better than O(n2) ?

Accepted 20.4K
Submissions 65.1K

0 ~ 6 months6 months ~ 1 year
1 year ~ 2 years
Amazon | 2 Google | 

Similar:
Max Points on a Line Hard
Number of Boomerangs Easy

Hint 1
Find the smallest and largest x-value for all points.
Hint 2
If there is a line then it should be at y = (minX + maxX) / 2.
Hint 3
For each point, make sure that it has a reflected point in the opposite side.


Topic: Hash Table, Math
