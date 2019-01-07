/*
这道题有点像围棋，将包住的O都变成X，但不同的是边缘的O不算被包围，跟之前那道Number of Islands 岛屿的数量很类似，都可以用DFS来解。刚开始我的思路是DFS遍历中间的O，如果没有到达边缘，都变成X，如果到达了边缘，将之前变成X的再变回来。但是这样做非常的不方便，在网上看到大家普遍的做法是扫面矩阵的四条边，如果有O，则用DFS遍历，将所有连着的O都变成另一个字符，比如$，这样剩下的O都是被包围的，然后将这些O变成X，把$变回O就行了

grandyang idea1, shaun java code, good idea, beats 42%
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
