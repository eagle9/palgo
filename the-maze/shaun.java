//shaun's own idea and java code, stackoverflow
//Feb 3 2019
class Solution {
    public boolean hasPath(int[][] maze, int[] start, int[] destination) {
        if (maze == null || maze[0].length == 0) return false;
        int m = maze.length, n = maze[0].length;
        if (maze[destination[0]][destination[1]] == 1)  return false;
        //now maze at dest.x&y must be 0
        return helper(maze, start, destination);
        
    }
    //go left, right, up and down
    private int [][] dirs = {{0,-1},{0,1},{-1,0},{1,0}};
    private boolean helper(int [][] maze, int [] start, int[] dest) {
        int m = maze.length, n = maze[0].length;
        for (int k  = 0; k < dirs.length; k++) {
            int x = start[0] + dirs[k][0];
            int y = start[1] + dirs[k][1];
            
            //make sure x and y in bound
            if (x < 0 || x >= m || y < 0 || y >= n ) continue;
            
            if (x == dest[0] && y == dest[1]) { 
                //next cell in dirs[k]
                int nx = x + dirs[k][0], ny = y + dirs[k][1];
                //can stop at dest case 1, nx & ny out bound so x&y is at border
                if (nx < 0 || nx >= m || ny < 0 || ny >= n )
                    return true;
                //can stop at dest case 2, nx&ny is wall
                if (maze[nx][ny] == 1) return true;
                //can not stop, try next direction
                else continue;
            }else { //x&y not yet reach dest
                return helper(maze, new int [] {x,y}, dest);
            }
            
        }
        
        //tried all, not return true
        return false;
        
    }
}
