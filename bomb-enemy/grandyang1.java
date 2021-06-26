//grandyang idea, shaun coded in java, beats 30%
public class Solution {
    /**
     * @param grid: Given a 2D grid, each cell is either 'W', 'E' or '0'
     * @return: an integer, the maximum enemies you can kill using one bomb
     */
    public int maxKilledEnemies(char[][] grid) {
        // write your code here
        //key point 1: add the corner case, otherwise Exception
        //key point 2: if grid[i][j] == '0', res = max(res, ....)
        if (grid.length ==0)
            return 0;
        if (grid[0].length == 0)
            return 0;
        int rows = grid.length, cols = grid[0].length;
        int [][] v1 = new int[rows][cols];
        int [][] v2 = new int[rows][cols];
        int [][] v3 = new int[rows][cols];
        int [][] v4 = new int[rows][cols];
        for (int i = 0; i < rows; i++) {
            //from left to right
            for (int j = 0; j < cols; j++) {
                int t = ((j==0) || (grid[i][j] == 'W'))? 0: v1[i][j-1];
                v1[i][j] = (grid[i][j] == 'E')? t+1: t;
            }
            //right right to left
            for (int j = cols-1; j >=0; j--) {
                int t = ((j==cols-1) || (grid[i][j] == 'W'))? 0: v2[i][j+1];
                v2[i][j] = (grid[i][j] == 'E')? t+1: t;
            }
        }
        for (int j = 0; j < cols; j++) {
            //from up to down
            for (int i =0; i < rows; i++) {
                int t = ((i==0) || (grid[i][j] == 'W'))? 0: v3[i-1][j];
                v3[i][j] = (grid[i][j] == 'E')? t+1: t;
            }
            //from down to up
            for (int i =rows-1; i >=0; i--) {
                int t = ((i==rows-1) || (grid[i][j] == 'W'))? 0: v4[i+1][j];
                v4[i][j] = (grid[i][j] == 'E')? t+1: t;
            }
        }
        
        int res = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                //can only place bomb at cells == '0'
                if (grid[i][j] == '0')
                    res = Math.max(res, v1[i][j]+v2[i][j]+v3[i][j]+v4[i][j]);
            }
        }
        return res;
    }
}


//grandyang, beats 54%
/*
四个累加数组v1, v2, v3, v4，其中v1是水平方向从左到右的累加数组，v2是水平方向从右到左的累加数组，v3是竖直方向从上到下的累加数组，v4是竖直方向从下到上的累加数组，我们建立好这个累加数组后，对于任意位置(i, j)，其可以炸死的最多敌人数就是v1[i][j] + v2[i][j] + v3[i][j] + v4[i][j]

*/

