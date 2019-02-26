/*shaun's own idea and code, accepted after 1 fix
Runtime: 3 ms, faster than 100.00% of Java online submissions for Number of Islands.
Memory Usage: 40.3 MB, less than 62.28% of Java online submissions for Number of Islands.

*/
class Solution {
	private int m, n;
    public int numIslands(char[][] grid) {
        //key to add the corner case
        if (grid == null || grid.length == 0) return 0;
        m = grid.length;
        n = grid[0].length;
    	boolean [][] visited = new boolean[m][n];
    	
    	int res = 0;
    	for (int i = 0; i < m; i ++) {
    		for (int j = 0; j < n; j++) {
                //once add grid[i][j] == '1', immedidately accepted
    			if (!visited[i][j] && grid[i][j] == '1') {
    				helper(i,j,visited, grid);
    				res++;
    			}
    		}
    	}
    	return res;
    }
    
    //visit i&j cell, then neighbors,
    //how to count islands
    private void helper(int i, int j, boolean[][] visited, char[][] grid) {
    	if (i < 0 || i >= m || j < 0 || j >=n ) return; //out bound
    	
    	if (visited[i][j]) return; //visited already
    	
    	if (grid[i][j] == '1') {
    		visited[i][j] = true;
    		helper(i+1,j, visited, grid);
    		helper(i-1,j, visited, grid);
    		helper(i,j+1, visited, grid);
    		helper(i,j-1, visited, grid);
    		
    	}
    	
    }
}
