//grandyan dfs with backtracking, shaun understood, 
//runtime 8ms, faster than 100%, mem less than 77%
class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > res;
        vector<int> pos(n, -1);
        solveNQueensDFS(pos, 0, res);
        return res;
    }
    //pos store Queue position(col index) at each row
    //row -- row to consider at the moment
    //res -- all possible valid Queue chessboard
    void solveNQueensDFS(vector<int> &pos, int row, vector<vector<string> > &res) {
        int n = pos.size();
        if (row == n) { //done all row, from 0 to n-1, can reach here, found a chessboard
            vector<string> board(n, string(n, '.'));
            for (int i = 0; i < n; ++i) {
                board[i][pos[i]] = 'Q';
            }
            res.push_back(board);
        } else {
            //try all col index at this row
            for (int col = 0; col < n; ++col) {
                if (isValid(pos, row ,col)) {
                    pos[row] = col;
                    solveNQueensDFS(pos, row + 1, res);
                    pos[row] = -1;
                }
            }
        }
    }
    //check if a new Queue at row,col will be compatible with queues from row 0 to row-1
    bool isValid(vector<int> &pos, int row, int col) {
        for (int i = 0; i < row; ++i) {
            if (col == pos[i] || abs(row - i) == abs(col - pos[i])) {
                return false;
            }
        }
        return true;
    }
};
