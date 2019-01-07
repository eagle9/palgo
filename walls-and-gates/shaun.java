//shaun has the right idea, but not accurate with the recusion exit condition, that resulted in stackoverflow, beats 75% 
class Solution {
    private int m = 0, n = 0;
    public void wallsAndGates(int[][] rooms) {
        //keypoint 1: without the following statement, index out of bound 
        if (rooms == null || rooms.length == 0) return;
        
        m = rooms.length;
        n = rooms[0].length;
        for (int i  = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rooms[i][j] == 0) helper(rooms, i, j,0);
            }
        }
    }
    //start from i&j, go left right up and down, update rooms array depth value
    private void helper(int [][] rooms, int i, int j, int depth) {
        //make sure i and j are in bound
        if (i < 0 || i > m-1 || j < 0 || j > n-1) return;
        //now i and j are all in bound
        //i & j is not wall
        if (rooms[i][j] == -1) return;
        
        //keypoint 1: without the following statement, there will be stackoverflow
        //if (rooms[i][j] < depth) return;
            
        if (rooms[i][j] > depth) rooms[i][j] = depth;
        else if (rooms[i][j] < depth) return; //no need to go there when <
        
        //>= recusion
        
        helper(rooms, i-1,j,depth+1);
        helper(rooms, i+1,j,depth+1);
        helper(rooms, i,j-1, depth+1);
        helper(rooms,i,j+1, depth+1);
        
    }
}

