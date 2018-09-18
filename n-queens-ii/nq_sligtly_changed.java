//based on jz n_queens solution, return results.size()
//Your submission beats 75.20% Submissions!
public class Solution {
    /**
     * @param n: The number of queens.
     * @return: The total number of distinct solutions.
     */
    public int totalNQueens(int n) {
        // write your code here
        List<List<String>> results = new ArrayList<>();
        // if(n <= 0){
        //     return results;
        // }
        
        dfs(n, new ArrayList<Integer>(), results);
        // int sum = 0;
        // for(int i = 0; i < results.size(); i++){
        //     sum ++;
        // }
        
        return results.size();
    }
    
    private void dfs(int n, List<Integer> cols, List<List<String>> results){
        if(cols.size() == n){
            results.add(drawChessboard(cols));
            return;
        }
        
        for(int i = 0; i < n; i++){
            if(isValid(cols, i)){
                cols.add(i);
                dfs(n, cols, results);
                cols.remove(cols.size() - 1);
            }
        }
    }
    
    private List<String> drawChessboard(List<Integer> cols){
        List<String> chessboard = new ArrayList<>();
        for(int i = 0; i < cols.size(); i++){
            StringBuilder sb = new StringBuilder();
            for(int j = 0; j < cols.size(); j++){
                sb.append(j == cols.get(i) ? "Q":".");
            }
            chessboard.add(sb.toString());
        }
        
        return chessboard;
    }
    
    private boolean isValid(List<Integer> cols, int column){
        int row = cols.size();
        for(int rowIndex = 0; rowIndex < cols.size(); rowIndex++){
            if(cols.get(rowIndex) == column){
                return false;
            }
            if(rowIndex + cols.get(rowIndex) == row + column){
                return false;
            }
            if(rowIndex - cols.get(rowIndex) == row - column){
                return false;
            }
        }
        
        return true;
    }
}
                                 
