// hua idea with shaun's review and comments
// Runtime: 4 ms, faster than 97%, mem less than 52%
//i tried vvb, somehow vvi is faster than vvb(bool), so stay with vvi use to track the use once rule

//cutting:  dfs with backtracking
//given a partially filled board, see if we can complete the board 
//fill board cell yx with a digit range from 1 to 9, track each row, col, box using a digit(1-9) once and only once
//so we come up with 3 vvi rows_, cols_ and boxes_ to track and guard only once usage
//start fill the cell y=0, x=0, see if we can successfully reach row 9 or y=9
//once fill current cell, recur to next cell
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        rows_ = vector<vector<int>>(9, vector<int>(10));
        cols_ = vector<vector<int>>(9, vector<int>(10));
        boxes_ = vector<vector<int>>(9, vector<int>(10));
        
        //fill the board with exisiting input
        //think how to identify each box with y and x, use example to figure out
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                const char c = board[i][j];                
                if ( c != '.') {
                    int n = c - '0';                    
                    int bx = j / 3;
                    int by = i / 3;
                    rows_[i][n] = 1;
                    cols_[j][n] = 1;
                    boxes_[by * 3 + bx][n] = 1;
                }
            }
        }
        
        //start fill from first cell 00, auto consider fill next cell
        fill(board, 0, 0);
    }
    
private:
    vector<vector<int>> rows_, cols_, boxes_;
    
    bool fill(vector<vector<char>>& board, int x, int y) {
        //start from y = 0, if we can reach to 9, then filling success
        if (y == 9)
            return true;
        
        //what's the next cell to fill? 
        int nx = (x + 1) % 9;  //col index from 0 to 8
        int ny = (nx == 0) ? y + 1 : y; //when y goes to next row??
        
        //if the cell yx already filled, boils down to filling next cell
        if (board[y][x] != '.') return fill(board, nx, ny);
        
        for (int i = 1; i <= 9; i++) {
            int bx = x / 3;
            int by = y / 3;
            int box_key = by * 3 + bx;
            //if digit i is not used by the row, col and box, then we can use i
            if (!rows_[y][i] && !cols_[x][i] && !boxes_[box_key][i]) {
                rows_[y][i] = 1;
                cols_[x][i] = 1;
                boxes_[box_key][i] = 1;
                board[y][x] = i + '0';
                //fill the cell with digit i, if we can fill next cell, return true
                //otherwise backtrack
                if (fill(board, nx, ny)) return true;
                board[y][x] = '.';
                boxes_[box_key][i] = 0;
                cols_[x][i] = 0;
                rows_[y][i] = 0;
            }
        }
        //tried all digits and can not fill, return false
        return false;
    }
};

