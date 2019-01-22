/*
求一个二维区域和的检索，是之前那道题Range Sum Query - Immutable 区域和检索的延伸。有了之前那道题的基础，我们知道这道题其实也是换汤不换药，还是要建立一个累计区域和的数组，然后根据边界值的加减法来快速求出给定区域之和。这里我们维护一个二维数组dp，其中dp[i][j]表示累计区间(0, 0)到(i, j)这个矩形区间所有的数字之和，那么此时如果我们想要快速求出(r1, c1)到(r2, c2)的矩形区间时，只需dp[r2][c2] - dp[r2][c1 - 1] - dp[r1 - 1][c2] + dp[r1 - 1][c1 - 1]即可，下面的代码中我们由于用了辅助列和辅助行，所以下标会有些变化，
grandyang idea dp, jz java code, runtime 88ms, faster than 39%

*/

public class NumMatrix {

    private int[][] dp = null;

    public NumMatrix(int[][] matrix) {
        if (matrix.length == 0 || matrix[0].length == 0) {
            return;
        }
        int n = matrix.length;
        int m = matrix[0].length;
        
        dp = new int[n + 1][m + 1];
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                dp[r + 1][c + 1] = dp[r + 1][c] + dp[r][c + 1] + matrix[r][c] - dp[r][c];
            }
        }
    }
    
    public int sumRegion(int row1, int col1, int row2, int col2) {
        return dp[row2 + 1][col2 + 1] - dp[row1][col2 + 1] - dp[row2 + 1][col1] + dp[row1][col1];
    }
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
