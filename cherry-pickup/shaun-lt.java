/*
ime Complexity: O(N^3)O(N^3), where NxN is the length of grid. 
Our dynamic programming has O(N^3) states.

Space Complexity: O(N^3), the size of memo.

lt idea, dp with memo, shaun understand
Runtime: 12 ms, faster than 92.10% of Java online submissions for Cherry Pickup.
Memory Usage: 39.6 MB, less than 83.33% of Java online submissions for Cherry Pickup.

*/
class Solution {
    int[][][] memo;
    int[][] grid;
    int N;
    public int cherryPickup(int[][] grid) {
        this.grid = grid;
        N = grid.length;
        memo = new int[N][N][N];
        for (int[][] layer: memo)
            for (int[] row: layer)
                Arrays.fill(row, Integer.MIN_VALUE);
        return Math.max(0, dp(0, 0, 0));
    }
    //max number of cherries from r1,c1 and r2,c2 to N-1,N-1
    //r1+c1 = r2 + c2, so c2 = r1+c1-c2, only 3 free variables
    public int dp(int r1, int c1, int c2) {
        
        int r2 = r1 + c1 - c2;
        //outbound reaching N, make sure it won't be taken through taking max
        if (N == r1 || N == r2 || N == c1 || N == c2 ||
                grid[r1][c1] == -1 || grid[r2][c2] == -1) {
            return Integer.MIN_VALUE;         
        }else if (memo[r1][c1][c2] != Integer.MIN_VALUE) {
            return memo[r1][c1][c2];
        }else if (r1 == N-1 && c1 == N-1) { //r2 = N-1 and c2 == N-1 too
            return grid[r1][c1];
        }else {
            int ans = grid[r1][c1];
            if (c1 != c2) ans += grid[r2][c2];
            //r1 c1 1 step forward r1+1,c1, or r1, c1+1
            //     c2 is free, so total 4 cases
            ans += Math.max(Math.max(dp(r1, c1+1, c2+1), dp(r1+1, c1, c2+1)),
                            Math.max(dp(r1, c1+1, c2), dp(r1+1, c1, c2)));
            memo[r1][c1][c2] = ans;
            return ans;
        }
    }
}
