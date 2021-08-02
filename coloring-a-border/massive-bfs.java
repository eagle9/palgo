//massive bfs idea https://massivealgorithms.blogspot.com/2019/06/leetcode-1034-coloring-border.html
class Solution {
    
    private static final int[][] d = {{0,1},{0,-1},{1,0},{-1,0}}; // neighbors' relative displacements.
    public int[][] colorBorder(int[][] grid, int r0, int c0, int color) {
        int clr = grid[r0][c0], m = grid.length, n = grid[0].length;
        Set<Integer> seen = new HashSet<>(); // put the cell number into Set to avoid visiting again.
        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[]{ r0, c0 }); // add initial cell.
        seen.add(r0 * n + c0); // add initial cell number.
        while (!q.isEmpty()) { // BFS starts.
            int [] temp = q.poll();
            int r = temp[0], c = temp[1];
             // on grid boundary.
            if (r == 0 || r == m - 1 || c == 0 || c == n - 1) { 
                grid[r][c] = color; 
            }
            for (int i = 0; i < 4; ++i) { // travers its 4 neighbors.
                int x = r + d[i][0], y = c + d[i][1]; // neighbor coordinates.
                
                // out of grid or visited already.
                if (x < 0 || x >= m || y < 0 || y >= n || seen.contains(x * n + y)) { continue; } 
                
                //in bound and not visited
                if (grid[x][y] == clr) { // its neighbor is of same color.
                    seen.add(x * n + y); // avoid visiting again.
                    q.offer(new int[]{ x, y }); // put it into Queue.
                }
                else { // its neighbor xy is of different color, hence rc is on component boundary. 
                    grid[r][c] = color;
                }
            }
        }
        return grid;
    }
}
