/*
shaun cutting with oldColor and newColor
dfs

Runtime: 0 ms, faster than 100.00% of Java online submissions for Flood Fill.
Memory Usage: 40.3 MB, less than 89.47% of Java online submissions for Flood Fill.
*/
class Solution {
    public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
        //int[][] ans = new [image.length][image[0].length];
        //Arrays.copyOf can only copy 1d array
        if (newColor == image[sr][sc]) return image;
        //Set<Integer> visited = new HashSet<>(); //not needed, wont go back since color changed to newColor, only color xy what is of oldColor
        //fill if color differs
        int color = image[sr][sc];
        helper(image,sr,sc,color,newColor);
        return image;
        
    }
    private static int [][] dirs = {{1,0},{-1,0},{0,1},{0,-1}};
    private void helper(int[][] image, int x, int y, int oldColor,int newColor) {
        if (image[x][y] != oldColor) return; //exit
        image[x][y] = newColor;
        for (int [] d: dirs) {
            int nx = x + d[0], ny = y + d[1];
            if (nx >= 0 && nx < image.length && ny >= 0 && ny < image[0].length) {
                helper(image,nx, ny, oldColor,newColor);
            }
        }
    }
}

