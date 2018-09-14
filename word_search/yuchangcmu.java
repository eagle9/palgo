//Your submission beats 72.20% Submissions!
//http://www.cnblogs.com/yuzhangcmu/p/4040418.html
public class Solution {
    public boolean exist(char[][] board, String word) {
        if (board == null || word == null 
             || board.length == 0 || board[0].length == 0) {
            return false;
        }
        
        int rows = board.length;
        int cols = board[0].length;
        
        boolean[][] visit = new boolean[rows][cols];
        
        // i means the index.
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // dfs all the characters in the matrix
                if (dfs(board, i, j, word, 0, visit)) {
                    return true;
                }
            }
        }
        
        return false;
    }
    
    public boolean dfs(char[][] board, int i, int j, String word, int wordIndex, boolean[][] visit) {
        int rows = board.length;
        int cols = board[0].length;
        
        int len = word.length();
        if (wordIndex >= len) {
            return true;
        }
        
        // the index is out of bound.
        if (i < 0 || i >= rows || j < 0 || j >= cols) {
            return false;
        }
        
        // the character is wrong.
        if (word.charAt(wordIndex) != board[i][j]) {
            return false;
        }
        
        // do not visit nodes that have been visited 
        if (visit[i][j] == true) {
            return false;
        }
        
        visit[i][j] = true;
        
        // recursion
        // move down
        if (dfs(board, i + 1, j, word, wordIndex + 1, visit)) {
            return true;
        }
        
        // move up
        if (dfs(board, i - 1, j,  word, wordIndex + 1, visit)) {
            return true;
        }
        
        // move right
        if (dfs(board, i, j + 1, word, wordIndex + 1, visit)) {
            return true;
        }
        
        // move left
        if (dfs(board, i, j - 1, word, wordIndex + 1, visit)) {
            return true;
        }
        
        // backtracking 
        visit[i][j] = false;
        return false;
    }
}
