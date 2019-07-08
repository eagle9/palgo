//huahua idea, runtime 1ms, faster than 100%, 1/26/2019
//shaun own java code, key points = use different bit to store different info
// keypoint 2: grasp the idea of simultaneous update and how to use binary number and bitwise operation and it op precedence. 
//cutting, how to write the neighbor checking loop and make sure index inbound, use min and max
//  challenge of in place computing, can not use extra array, but we need additional storage, how? 
//       use different bits!!!!!
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        if (m == 0) return;
        //int n = m ? board[0].size() : 0;
        int n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                //count of live neighbors of ij       
                int count = 0;
                // Scan the 3x3 region centered at (j, i).
                for (int y = max(0, i - 1); y <= min(m-1, i + 1); ++y) {
                    for (int x = max(0, j - 1); x <= min(n-1, j + 1); ++x) {
                        //count += board[y][x] & 1;
                        if (y == i && x == j) continue;
                        //use low bit only for cell live/dead status
                        count += board[y][x] & 0b01;
                    }
                }
                //key technique for in place computing, with out extra varialbes or array
                //  use different bits!!!!
                //use lowest bit for current life, 
                //update life for next generation and store it to second bit
                //store to 2nd bit, no change to low bit
                if (count < 2 && (board[i][j] &1) == 1)  //rule 1 live cell with <2 live neighbors
                    //continue; //dies in the next gen, 2nd bit is 0 already, continue works
                    board[i][j] &= 0b01;     //2nd bit to 0, no change to low bit, works too
                
                //rule 2 ---live cell with 2 or 3 live neighbors continue lives
                //2nd bit to 1, 1st bit no change ---> |0b10
                if ((count == 2 || count == 3) && (board[i][j] & 1) == 1) 
                    board[i][j] |= 0b10; //continue to live next gen
                //rule 3 -- live cell with >3 live neighbors dies
                // 2nd bit to 0, no change to 1st big   &0b01
                if (count > 3 && (board[i][j] &1) == 1) 
                    //continue; //dies
                    board[i][j] &= 0b01;
                //rule 4 --- dead cell with =3 live neighbors becomes live
                //  2nd bit to 1, no change to 1st bit
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
};


