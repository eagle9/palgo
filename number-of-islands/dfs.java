public class Solution {
    private int m, n; //number of rows and columns
    /**
     * @param grid a boolean 2D matrix
     * @return an integer
     */
    public int numIslands(boolean[][] grid) {
        m = grid.length;
        if (m == 0) {
            return 0;
        }
        n = grid[0].length;
        if (n == 0) {
            return 0;
        }
        int nums = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == false) {
                    continue;
                }
                nums++;
                //dfs(grid, i, j);
                bfs2(grid,i,j);
            }
        }
        return nums;
    }
    
    private void bfs2(boolean [][] grid, int i, int j) {
        
        LinkedList<Integer> queue = new LinkedList<>();
        queue.offer(i);queue.offer(j);
        while (!queue.isEmpty()) {
            i = queue.poll();
            j = queue.poll();
            if (grid[i][j] == true) {
                grid[i][j] = false;
               
                if (inBound2(i,j-1)) {
                    queue.offer(i);queue.offer(j-1);
                }
                if (inBound2(i,j+1)) {
                    queue.offer(i);queue.offer(j+1);
                }
                if (inBound2(i-1,j)) {
                    queue.offer(i-1);queue.offer(j);
                }
                if (inBound2(i+1,j)) {
                    queue.offer(i+1);queue.offer(j);
                }
    
            }
        }
    }
    private class Coord {
        int x,y;
        Coord(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
    private void bfs(boolean [][] grid, int i, int j) {
        
        LinkedList<Coord> queue = new LinkedList<>();
        queue.offer(new Coord(i,j));
        while (!queue.isEmpty()) {
            Coord c = queue.poll();
            if (grid[c.x][c.y] == true) {
                grid[c.x][c.y] = false;
                Coord c1 = new Coord(c.x-1,c.y);
                if (inBound(c1))
                    queue.offer(c1);
                Coord c2 = new Coord(c.x+1,c.y);
                if (inBound(c2))
                    queue.offer(c2);
                Coord c3 = new Coord(c.x,c.y-1);
                if (inBound(c3))
                    queue.offer(c3);
                Coord c4 = new Coord(c.x,c.y+1);
                if (inBound(c4))
                    queue.offer(c4);
            }
        }
    }
    
    private boolean inBound2( int i, int j) {
        if (i <0  || i >= m || j < 0 || j >= n)
            return false;
        else
            return true;
    }
    
    private boolean inBound(Coord c) {
        if (c.x < 0 || c.x >= m || c.y< 0 ||c.y >= n) //return when out of bound
            return false;
        else 
            return true;
    }
    
    private void dfs(boolean[][] grid, int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n) {
            return;
        }
        if (grid[i][j] == true) {
            grid[i][j] = false;
            dfs(grid, i - 1, j);
            dfs(grid, i + 1, j);
            dfs(grid, i, j - 1);
            dfs(grid, i, j + 1);
        }
    }

    
}
