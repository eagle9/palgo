/*

shaun own in a bad mode, 1 error then fixed
count neighbors

*/
    
    
    
class Solution {
    public int islandPerimeter(int[][] grid) {
        int ans = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] == 1) {
                    ans += 4 - nei(i,j, grid);
                }
            }
        }
        return ans;
    }
    
    //neighbor count up, dn, left and right
    private int nei(int i, int j, int [][] grid) {
        int count = 0;
        //up, i-1
        if (i-1 >=0 && i-1 < grid.length && grid[i-1][j] == 1)
            count++;
        //down i+1
        if (i+1 >=0 && i+1 < grid.length && grid[i+1][j] == 1)
            count++;
        
        //left, j-1
        if (j-1 >=0 && j-1 < grid[0].length && grid[i][j-1] == 1)
            count++;
        
        //right, j+1
        if (j+1 >=0 && j+1 < grid[0].length && grid[i][j+1] == 1)
            count++;
        
    
        return count;
    }
}
