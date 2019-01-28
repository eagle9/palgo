//grandyang idea, shaun own java code, 
//use array as hashtable, key is to come up with cell index
//runtime 13ms, faster than 99%
class Solution {
    public boolean isValidSudoku(char[][] board) {
        if (board == null || board.length == 0 ) return false;
        int m = board.length, n = board[0].length;
        if (m != 9 || n != 9) return false;
        //for each row, if a number 1-9 has been used
        boolean [] [] rowFlag = new boolean[9][9];
        boolean [] [] colFlag = new boolean[9][9];
        boolean [] [] cellFlag= new boolean[9][9];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] != '.') {
                //if (board[i][j] >= '1' && board[i][j] <= '9') {
                    //find the number used
                    int x = board[i][j] - '1';   //x from 0 to 8
                    //used, return false, not valid
                    //int cell = 3*i/3 + j/3;
                    int cell = 3*(i/3) + j/3;
                    
                    if (rowFlag[i][x] || colFlag[j][x] ||cellFlag[cell][x]) return false;
                    //x not yet used, now use it and update flags
                    rowFlag[i][x] = true;
                    colFlag[j][x] = true;
                    cellFlag[cell][x] = true;
                }
            }
        }
        //passed all tests
        return true;
        
    }
}


