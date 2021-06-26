//jz dfs with backtracking, shaun understood, i think it is better than grandyang's 
//runtime 8ms, faster than 100%, mem less than 77%
class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > res;
        vector<int> pos;
        dfs(n,pos, res);
        return res;
    }
    //cur store Queue position(col index) at each row
    //res -- all possible valid Queue chessboard
    void dfs(int n, vector<int> &cur, vector<vector<string> > &res) {
        
        if (cur.size() == n) { //done all row, from 0 to n-1, can reach here, found a chessboard
            vector<string> board(n, string(n, '.'));
            for (int i = 0; i < n; ++i) {
                board[i][cur[i]] = 'Q';
            }
            res.push_back(board);
        } else {
            //try all col index at next 
            for (int col = 0; col < n; ++col) {
                if (isValid(cur, col)) {
                    cur.push_back(col);
                    dfs(n,cur, res);
                    cur.pop_back();
                }
            }
        }
    }
    //check if a new Queue at row,col will be compatible with queues from row 0 to row-1
    bool isValid(vector<int> &pos, int col) {
        int row = pos.size();
        for (int i = 0; i < row; ++i) {
            if (col == pos[i] || abs(row - i) == abs(col - pos[i])) return false;
        }
        return true;
    }
};
