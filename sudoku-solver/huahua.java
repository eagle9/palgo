//huahua's idea, pretty good, shaun java code
//runtime 6ms, faster than 97%
//keypoints: 1 -- box key, 2 -- how to recursive call, exit and next level
//1/26/2019
class Solution {
    
    public void solveSudoku(char[][] board) {
        //update the flags with existing numbers on the board
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') { //is a number
                    int n = board[i][j] - '1'; //number from 0 to 8
                    rowFlag[i][n] = true;
                    colFlag[j][n] = true;
                    int box = (i/3)*3 + j/3;
                    boxFlag[box][n]=true;
                }
            }
        }
        //fill the board recurisve from 00
        fill(board,0,0);
    }
    private boolean [] [] rowFlag = new boolean[9][9];
    private boolean [] [] colFlag = new boolean[9][9];
    private boolean [] [] boxFlag= new boolean[9][9];  //3x3 box
    
    //be clear with x y and board index
    private boolean fill(char [][] board, int x, int y) {
        if (y == 9) return true;
        int nx = (x+1) % 9;
        int ny = (nx ==0)? y+1: y;
        //yx has a number already, go fill next
        if (board[y][x] != '.') return fill(board, nx, ny);
        //now try to fill yx with number 1 to 9
        for (int i = 1; i <= 9; i++) {
            int box = (y/3)*3 + x/3;
            //number i is not yet used by col, row, or box
            if (!rowFlag[y][i-1] && !colFlag[x][i-1] && !boxFlag[box][i-1]) {
                rowFlag[y][i-1] = true;
                colFlag[x][i-1] = true;
                boxFlag[box][i-1] = true;
                //board[y][x] = Character.valueOf(i); //not work valueOf(char)
                board[y][x] = (char) ('0' + i);
                //go fill next
                if (fill(board,nx,ny)) return true;
                //else, back track and try next number
                rowFlag[y][i-1] = false;
                colFlag[x][i-1] = false;
                boxFlag[box][i-1] = false;
                board[y][x] = '.';
                
            }
        }
        //could not fill 
        return false;
    }
}

