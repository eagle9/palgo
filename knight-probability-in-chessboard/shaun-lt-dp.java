/*

Let f[r][c][steps] be the probability of being on square (r, c) after steps steps. Based on how a knight moves, we have the following recursion:

use two two-dimensional ones dp and dp2, storing the result of the two most recent layers we are working on. dp2 will represent f[][][steps], and dp will represent f[][][steps-1].


lt dp idea, dp [][] naturally init xy cell 1, other all 0
populate dp2[][], repeats 
Runtime: 14 ms, faster than 14.81% of Java online submissions for Knight Probability in Chessboard.
Memory Usage: 39.4 MB, less than 33.33% of Java online submissions for Knight Probability in Chessboard.
*/
class Solution {
    public double knightProbability(int N, int K, int sr, int sc) {
        double[][] dp = new double[N][N];
        int[] dr = new int[]{2, 2, 1, 1, -1, -1, -2, -2};
        int[] dc = new int[]{1, -1, 2, -2, 2, -2, 1, -1};

        dp[sr][sc] = 1; //other coordinates =0
        //now direct dp2 for all cells
        for (int reps = 0; reps < K; reps++) {
            double[][] dp2 = new double[N][N];
            for (int r = 0; r < N; r++) {
                for (int c = 0; c < N; c++) {
                    for (int k = 0; k < 8; k++) {
                        int cr = r + dr[k];
                        int cc = c + dc[k];
                        if (0 <= cr && cr < N && 0 <= cc && cc < N) {
                            dp2[cr][cc] += dp[r][c] / 8.0;
                        }
                    }
                }
            }
            dp = dp2;
        }
        double ans = 0.0;
        for (double[] row: dp) {
            for (double x: row) ans += x;
        }
        return ans;
    }
}
