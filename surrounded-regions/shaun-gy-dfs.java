/*
grandyang idea1 with dfs
dfs to grow from O cells on the border, and mark open O cells as T
then mark all remaining O cells (surrounded) to X
restore all T cells to O
runtme 2ms, faster than 52%, mem less than 86%
*/
class Solution {
    public void solve(char[][] board) {
        //key to add null and 0 test
        if (board == null || board.length == 0) return;
        
        int m = board.length;
        int n = board[0].length;
        
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
    private void helper(char [][] board, int i, int j) {
        if (board[i][j] == 'O') {
            board[i][j] = 'T';
            int m = board.length;
            int n = board[0].length;
            //go left,  i, j-1
            if (j >= 1) helper(board, i, j-1);
            //go right, i, j+1
            if (j <= n-2) helper(board,i,j+1);
            //go up, i-1,j
            if (i >= 1) helper(board, i-1,j);
            //go down, i+1, j
            if (i <= m-2) helper(board,i+1,j);
        }
    }
}


