//grandyang dfs idea with memoization, dp array is not for dynamic programming
//instead it is a way of memoization
//runtime 9ms, faster than 77%
//understand now, Feb 3 2019
class Solution {
    //4 directions:  left, right, up, down
    int [][] dirs = {{0,-1},{0,1},{-1,0},{1,0}};
    public int longestIncreasingPath(int[][] matrix) {
        if (matrix == null || matrix.length ==0) return 0;
        int res = 1; //at least 1, single node in the path, starting node
        int m = matrix.length, n = matrix[0].length;
        int [][] dp = new int[m][n];
        //start with all possible starting cells i&j
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res = Math.max(res, helper(matrix, dp, i, j));
            }
        }
        return res;
        
    }
    //find longest inc path from i&j
    private int helper(int [][] matrix, int [][] dp, int i, int j) {
        if (dp[i][j] > 0) return dp[i][j]; ///why???? no repeat computation, with out this TLE
        int res = 1;
        int m = matrix.length, n = matrix[0].length;
        //all possible next cells
        for (int [] d: dirs) {
            int x = i + d[0], y = j + d[1];
            //make sure x&y are in bound and increasing
            // or continue if x or y not in bound or not increasing
            if (x < 0 || x >= m || y < 0 || y >= n || matrix[i][j] >= matrix[x][y]) continue;
            int len = 1 + helper(matrix, dp,x,y);
            res = Math.max(res, len);
        }
        dp[i][j] = res;
        return res;
    }
}

