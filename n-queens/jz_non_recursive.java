//jz java non recursive, using stack
//Your submission beats 86.80% Submissions!
public class Solution {
    /*
     * @param n: The number of queens
     * @return: All distinct solutions
     */
    public List<List<String>> solveNQueens(int n) {
        List<List<String>> results = new ArrayList<>();
        if (n <= 0) {
            return results;
        }

        //queen's col position at row i
        int[] queen = new int[n];

        // DFS with stack
        //Deque<Integer> stack = new ArrayDeque<>();
        Stack<Integer> stack = new Stack<>();
        
        boolean goNextRow;
        
        stack.push(0);
        int row = 0;
        while (!stack.isEmpty()) {
            goNextRow = false;
            int col = stack.pop();
            //find a single valid col position
            while (col < n) {
                if (isValid(queen,row, col)) {
                    queen[row] = col;
                    //go deeper, push next col position into stack
                    stack.push(col + 1);
                    goNextRow = true;
                    break; //only need to find 1 valid position
                }
                col++;
            }

            if (goNextRow) {
                if (row == n-1) { //candidate is complete now
                    results.add(draw(queen));
                } else {
                    row++;
                    //col position for next row is 0,
                    stack.push(0);
                }
            } else { //no valid position found, go back 1 row
                row--;
            }
        }

        return results;
    }

    //draw chessboard
    //each row is a string ...Q.... where Q is at 4th column
    private List<String> draw(int [] queens) {
        int n = queens.length;
        List<String> chessboard = new ArrayList<>(n);
        for (int i = 0; i < n; i++) {
            int col = queens[i]; //col position for row i
            StringBuilder sb = new StringBuilder();
            for (int j = 0; j < n; j++) {
                sb.append(j == col ? 'Q' : '.');
            }
            chessboard.add(sb.toString());
        }
        return chessboard;
    }

    private boolean isValid(int[] queens, int row, int col) {
        int n = queens.length;
        for (int r = row-1; r >=0 ; r--) {
            int c = queens[r];
            if (col == c) return false; //same column
            if (Math.abs(col - c) == Math.abs(row - r)) return false; //diagonal check
        }
        return true;
    }
}

