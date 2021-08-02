//massive dfs
//https://massivealgorithms.blogspot.com/2019/06/leetcode-1034-coloring-border.html
class Solution {
    
    private int[] d = { 0, 1, 0, -1, 0 }; // neighbors' relative displacements.
    public int[][] colorBorder(int[][] grid, int r0, int c0, int color) {
        dfs(grid, r0, c0, grid[r0][c0]);
        for (int[] g : grid) {
            for (int i = 0; i < g.length; ++i) {
                if (g[i] < 0) { g[i] = color; }
            }
        }
        return grid;
    }
    private void dfs(int[][] grid, int r, int c, int clr) {
        grid[r][c] = -clr; // mark as visited.
        int cnt = 0; // use to count grid[r][c]'s component neighbors (same color as itself).
        for (int i = 0; i < 4; ++i) { // traverse 4 neighbors.
            int x = r + d[i], y = c + d[i + 1]; // nieghbor's coordinates.
            if (x < 0 || x >= grid.length || y < 0 || y >= grid[0].length || Math.abs(grid[x][y]) != clr) { continue; } // out of grid or not same component.
            ++cnt; // only if all 4 neighbors of grid[r][c] have same color as itself, it is on inner part.
            if (grid[x][y] == clr) { dfs(grid, x, y, clr); }
        }
        if (cnt == 4) { grid[r][c] = clr; } // inner part, change back.
    }
}
