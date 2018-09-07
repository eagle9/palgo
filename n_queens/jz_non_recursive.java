//jz java non recursive, using stack
//Your submission beats 67.20% Submissions!
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

        // row: col
        int[] queen = new int[n];

        // DFS
        Deque<Integer> stack = new ArrayDeque<>();
        int row = 0, col;
        boolean goNextRow;

        stack.push(0);
        while (!stack.isEmpty()) {
            goNextRow = false;
            col = stack.pop();
            while (col < n) {
                if (isAvailable(n, queen, row, col)) {
                    queen[row] = col;
                    stack.push(col + 1);
                    goNextRow = true;
                    break;
                }
                col++;
            }

            if (goNextRow) {
                if (row + 1 == n) {
                    results.add(drawResult(n, queen));
                } else {
                    row++;
                    stack.push(0);
                }
            } else {
                row--;
            }
        }

        return results;
    }

    private List<String> drawResult(int n, int[] queen) {
        List<String> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int q = queen[i];
            String str = "";
            for (int j = 0; j < n; j++) {
                if(j == q) {
                    str += "Q";
                } else {
                    str += ".";
                }
            }
            list.add(str);
        }
        return list;
    }

    private boolean isAvailable(int n, int[] queen, int row, int col) {
         for (int i = 1; row - i >= 0; i++) {
            int prevQ = queen[row - i];
            if (col == prevQ) {
                return false;
            }
            if (col - i >= 0 && col - i == prevQ) {
                return false;
            }
            if (col + i < n && col + i == prevQ) {
                return false;
            }
        }
        return true;
    }
}
