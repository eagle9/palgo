/*
grandyang idea 3 dp, runtime 14ms, faster than 63%
the version that is the easest to understand and remember
进一步的优化时间复杂度到O(n2)，做法是使用DP，简历一个二维dp数组，其中dp[i][j]表示到达(i, j)位置所能组成的最大正方形的边长。我们首先来考虑边界情况，也就是当i或j为0的情况，那么在首行或者首列中，必定有一个方向长度为1，那么就无法组成长度超过1的正方形，最多能组成长度为1的正方形，条件是当前位置为1。边界条件处理完了，再来看一般情况的递推公式怎么办，对于任意一点dp[i][j]，由于该点是正方形的右下角，所以该点的右边，下边，右下边都不用考虑，关心的就是左边，上边，和左上边。这三个位置的dp值suppose都应该算好的，还有就是要知道一点，只有当前(i, j)位置为1，dp[i][j]才有可能大于0，否则dp[i][j]一定为0。当(i, j)位置为1，此时要看dp[i-1][j-1], dp[i][j-1]，和dp[i-1][j]这三个位置，我们找其中最小的值，并加上1，就是dp[i][j]的当前值了，这个并不难想，毕竟不能有0存在，所以只能取交集，最后再用dp[i][j]的值来更新结果res的值即可
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

*/
class Solution {
    public int maximalSquare(char[][] matrix) {
        if (matrix.length == 0 || matrix[0].length == 0) return 0;
        int m = matrix.length, n = matrix[0].length, res = 0;
		//dp i j is the edge length of square with right bottom corner at i,j
		//init and tabulate direction
		// ------
		// |->
		// |->
        int [][] dp = new int[m][n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || j == 0) dp[i][j] = matrix[i][j] - '0';
                else if (matrix[i][j] == '1') {
                    dp[i][j] = Math.min(dp[i - 1][j - 1], Math.min(dp[i][j - 1], dp[i - 1][j])) + 1;
                }
                res = Math.max(res, dp[i][j]);
            }
        }
        return res * res;
    }
}
