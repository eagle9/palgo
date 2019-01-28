//huahua idea, runtime 1ms, faster than 100%, 1/26/2019
//shaun own java code, key points = use different bit to store different info
// keypoint 2: grasp the idea of simultaneous update and how to use binary number and bitwise operation and it op precedence. 
class Solution {
    public void gameOfLife(int[][] board) {
        int m = board.length;
        if (m == 0) return;
        //int n = m ? board[0].size() : 0;
        int n = board[0].length;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                //count of live neighbors of ij       
                int count = 0;
                // Scan the 3x3 region including (j, i).
                for (int y = Math.max(0, i - 1); y <= Math.min(m-1, i + 1); ++y) {
                    for (int x = Math.max(0, j - 1); x <= Math.min(n-1, j + 1); ++x) {
                        //count += board[y][x] & 1;
                        if (y == i && x == j) continue;
                        //use low bit only for current board state
                        count += board[y][x] & 0b01;
                    }
                }
                //use lowest bit for current life, 
                //update life for next generation and store it to second bit
                //store to 2nd bit, no change to low bit
                if (count < 2 && (board[i][j] &1) == 1) 
                    //continue; //dies in the next gen, 2nd bit is 0 already, continue works
                    board[i][j] &= 0b01;     //2nd bit to 0, no change to low bit, works too
                if ((count == 2 || count == 3) && (board[i][j] & 1) == 1) 
                    board[i][j] |= 0b10; //continue to live next gen
                if (count > 3 && (board[i][j] &1) == 1) 
                    continue; //dies
                if (count == 3 && (board[i][j] &1) == 0) 
                    board[i][j] |= 0b10; //live next gen
                
            }
            
        }
        //now update entire board at the same time
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                board[i][j] = board[i][j] >> 1; //move 2nd bit to low bit
            }
        }
        
    }
}
