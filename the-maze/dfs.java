//https://leetcode.com/problems/the-maze/discuss/97089/java-dfs-solution-could-anyone-tell-me-how-to-calculate-the-time-complexity
//runtime 7ms, faster than 76%, depth-first search
//grandyang based his dfs on this one
//to understand
public class Solution {
    
    int[][] dirs = new int[][]{{1,0},{-1,0},{0,1},{0,-1}};
    public boolean hasPath(int[][] maze, int[] start, int[] destination) {
        if(maze.length ==0){
            return false;
        }
        if(maze[start[0]][start[1]] == 1 || maze[destination[0]][destination[1]] ==1){
            return false;
        }
        
        int row = maze.length;
        int col = maze[0].length;
        Boolean[][] memo = new Boolean[row][col];
        return helper(maze, memo, start[0], start[1], destination[0], destination[1], row, col);
        
    }
    
    
    public boolean helper(int[][] maze, Boolean[][] memo, int si, int sj, int di, int dj, int row, int col){
        if(si == di && sj == dj){
            return true;
        }
        
        if(memo[si][sj] != null){
            return memo[si][sj];
        }
        
        maze[si][sj] = -1; // mark as visited.
        
        boolean res = false;
        for(int[] dir : dirs){
            // until we reach the edge or wall;
            
            int x = si;
            int y = sj;
            
            while(x+dir[0] >=0 && x+dir[0] < row && y+dir[1] >=0 && y+dir[1] < col && maze[x+dir[0]][y+dir[1]] != 1){
                x+=dir[0];
                y+=dir[1];
            }
            
            //so that x,y is the next point in this direction;
            
            if(maze[x][y] != -1){
                res |=helper(maze, memo, x, y, di, dj, row, col);
            }
        }
        
        maze[si][sj] = 0;
        memo[si][sj] = res;
        
        return res;
    }
}
