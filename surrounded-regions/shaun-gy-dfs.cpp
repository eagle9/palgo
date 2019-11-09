/*
grandyang idea1 with dfs
dfs to grow from O cells on the border, and mark open O cells as T
then mark all remaining O cells (surrounded) to X
restore all T cells to O
runtme 32ms, faster than 56%, mem less than 97%
*/
class Solution {
public:
    void solve(vector<vector<char>>& board) { //bug 1, use ref &
        //key to add null and 0 test
        if (board.empty()) return;
        
        int m = board.size();
        int n = board[0].size();
        
        //scan all 4 edges and mark O and its connected O to 'T'
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || i == m-1 || j == 0 || j == n-1) {
                    if (board[i][j] == 'O') helper(board, i, j);
                }
            }
        }
        
        //now all the Os are surrounded, bordering Os changed to Ts.
        //only need to do the simple update: scan the 2d array again, O -> X, and T -> O
        for (int i =0; i < m; i++) {
            for (int j =0; j < n; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == 'T') board[i][j] = 'O';
            }
        }
    }
    //if ij == 'O', change it to 'T' recursively for left, right, up and down direction O
private:
    void helper(vector<vector<char>>& board, int i, int j) {
        if (board[i][j] == 'O') {
            board[i][j] = 'T';
            int m = board.size();
            int n = board[0].size();
            //go left,  i, j-1
            if (j -1 >=0) helper(board, i, j-1);
            //go right, i, j+1
            if (j+1 <= n-1) helper(board,i,j+1);
            //go up, i-1,j
            if (i -1>= 0) helper(board, i-1,j);
            //go down, i+1, j
            if (i+1 <= m-1) helper(board,i+1,j);
        }
    }
};

