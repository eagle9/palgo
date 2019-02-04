//grandyang dp idea, shaun java code, runtime 16ms, faster than 63%
class Solution {
    public int longestLine(int[][] M) {
        if (M == null || M.length == 0) return 0;
        int m = M.length, n = M[0].length, res = 0;
        //dp[i][j][k]表示从开头遍历到数字nums[i][j]为止，第k种情况的连续1的个数
        int [][][] dp = new int[m][n][4];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (M[i][j] == 0) continue;
                //M[i][j] == 1, path len 1, not quite understood the following line 
                for (int k = 0; k < 4; ++k) dp[i][j][k] = 1;
                
                if (j > 0) dp[i][j][0] += dp[i][j - 1][0]; // horizonal
                if (i > 0) dp[i][j][1] += dp[i - 1][j][1]; // vertical
                if (i > 0 && j < n - 1) dp[i][j][2] += dp[i - 1][j + 1][2]; // diagonal
                if (i > 0 && j > 0) dp[i][j][3] += dp[i - 1][j - 1][3]; // anti-diagonal
                for (int k = 0; k < 4; k++)
                    res = Math.max(res, dp[i][j][k]);
            }
        }
        return res;
    }
}
