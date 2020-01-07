//lt discuss and shaun modified to his own template and understanding
//runtime 11ms, faster than 86%, mem less than 100%
class Solution {
     //return maxGold starting from xy
     private int explore(int[][] grid, int x, int y, boolean visited[][]) {
        int maxGold = 0;
         //outbound or visited already
        if (x < 0 || x >= grid.length || y < 0 || 
            y >= grid[0].length || visited[x][y])
            return 0;
        visited[x][y] = true;
        if (grid[x][y] == 0) return 0;
        
        maxGold = Math.max(maxGold, explore(grid, x + 1, y, visited));
        maxGold = Math.max(maxGold, explore(grid, x - 1, y, visited));
        maxGold = Math.max(maxGold, explore(grid, x, y + 1, visited));
        maxGold = Math.max(maxGold, explore(grid, x, y - 1, visited));
         //back track
        visited[x][y] = false;
        
        return grid[x][y] + maxGold;
    }
    public int getMaximumGold(int[][] grid) {
        int maxGold = Integer.MIN_VALUE;
        //okay to put visited here, since after each xy visited, reset to false
        
        
        //try all starting point
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                //if (!visited[i][j]) {
                    boolean visited[][] = new boolean[grid.length + 1][grid[0].length + 1];
                    maxGold = Math.max(maxGold, explore(grid, i, j, visited));
                //}
            }
        }
        return maxGold;
    }
}

