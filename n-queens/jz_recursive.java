//jz java recursive, Your submission beats beats 90.40% Submissions!
class Solution {
    /**
     * Get all distinct N-Queen solutions
     * @param n: The number of queens
     * @return: All distinct solutions
     * For example, A string '...Q' shows a queen on forth position
     */
    List<List<String>> solveNQueens(int n) {
        List<List<String>> res = new ArrayList<>();
        if (n <= 0) {
            return res;
        }
        
        dfs(res, new ArrayList<Integer>(), n);
        return res;
    }
    
    /*
     * @param cols: store the column indices for each row, this is the search candidate
     * @param res: store all of the chessboards
     * @param n: chess board size
     */
    private void dfs(List<List<String>> res, List<Integer> cols, int n) {
        //recusion exit, for col position for all n queens 
        if (cols.size() == n) {
            res.add(draw(cols));
            return;
        }
        
        for (int colIndex = 0; colIndex < n; colIndex++) {
            if (!isValid(cols, colIndex)) {
                continue;
            }
            //add a good colIndex to cols candidate
            cols.add(colIndex);
            //go deeper
            dfs(res, cols, n);
            //back tracking 
            cols.remove(cols.size() - 1);
        }
    }
    
    //draw chessboard
    //each row is a string ...Q.... where Q is at 4th column
    private List<String> draw(List<Integer> cols) {
        List<String> chessboard = new ArrayList<>();
        int n = cols.size();
        for (int i = 0; i < n; i++) {
            int col = cols.get(i); //col position for row i
            StringBuilder sb = new StringBuilder();
            for (int j = 0; j < n; j++) {
                sb.append(j == col ? 'Q' : '.');
            }
            chessboard.add(sb.toString());
        }
        return chessboard;
    }
    
    private boolean isValid(List<Integer> cols, int column) {
        int row = cols.size();
        for (int rowIndex = 0; rowIndex < cols.size(); rowIndex++) {
            int colIndex = cols.get(rowIndex);
            //same column, not valid
            if (colIndex == column)  return false;
            //diagonal
            if (Math.abs(rowIndex - row) == Math.abs(colIndex - column))  return false;
            //if (rowIndex - colIndex == row - column)  return false;
        }
        return true;
    }
}
