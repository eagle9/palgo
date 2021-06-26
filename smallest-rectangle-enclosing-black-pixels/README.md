302. Smallest Rectangle Enclosing Black Pixels
Hard
An image is represented by a binary matrix with 0 as a white pixel and 1 as a black pixel. The black pixels are connected, i.e., there is only one black region. Pixels are connected horizontally and vertically. Given the location (x, y) of one of the black pixels, return the area of the smallest (axis-aligned) rectangle that encloses all black pixels.

Example:
Input:
[
  "0010",
  "0110",
  "0100"
]
and x = 0, y = 2

Output: 6
0 ~ 6 months6 months ~ 1 year1 year ~ 2 years
Google | 2

idea forming
natural to think of rectangle bottom, top, left right and dfs or bfs
the time complexity with be O(m*n)

