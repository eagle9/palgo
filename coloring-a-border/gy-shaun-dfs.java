/*gy dfs, shaun understood

Input: grid = [[1,2,2],
               [2,3,2]], r0 = 0, c0 = 1, color = 3
               
               1 -2 -2
               2 3  -2
Output: [[1, 3, 3]
       , [2, 3, 3]]
       
       
       [[1,1,1], r0 = 1, c0 = 1, color = 2
        [1,1,1],
        [1,1,1]]
        
        Output: [[2, 2, 2],
                 [2, 1, 2],
                 [2, 2, 2]]
        

*/
class Solution {
    public int[][] colorBorder(int[][] grid, int r0, int c0, int color) {
        helper(grid, r0, c0, grid[r0][c0]);
        for (int i = 0; i < grid.length; ++i) {
            for (int j = 0; j < grid[0].length; ++j) {
                if (grid[i][j] < 0) grid[i][j] = color;
            }
        }
        return grid;
    }
    
    //color x,y to -c if grid[x,y] == c
    void helper(int [][] grid, int x, int y, int c) {
        int m = grid.length, n = grid[0].length;
        //out of bound or not the same color
        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != c) return;
        //inbound set color and color is c
        grid[x][y] = -c;
        //conditionally set color to its 4 neighbors
        helper(grid, x - 1, y, c); //up
        helper(grid, x + 1, y, c); //down
        helper(grid, x, y - 1, c); //left
        helper(grid, x, y + 1, c); //right
        
        //是否是边缘，不是边缘的话，要还原为正数, check the ask, no need to color interior
        //interior cell and its neighboring color c cells
        if (x > 0 && x < m - 1 && y > 0 && y < n - 1 
            && c == Math.abs(grid[x - 1][y])
            && c == Math.abs(grid[x + 1][y])
            && c == Math.abs(grid[x][y - 1])
            && c == Math.abs(grid[x][y + 1])) {
            grid[x][y] = c;
        }
    }
}
