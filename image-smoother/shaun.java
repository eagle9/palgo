//shaun own, first sub error
//second sub accepted, put inbound check inside loop body instead of loop exit condition
//runtime 4ms, faster than 98%, mem less than 81%
class Solution {
    public int[][] imageSmoother(int[][] M) {
        int m = M.length;
        //if (m == 0) Exception;
        int n = M[0].length;
        int [][] res = new int[m][n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                res[i][j] = smooth(M,i,j);
            }
        }
        return res;
    }
    private int smooth(int [][] M, int i, int j) {
        int res = 0, count = 0;
        for (int dx = -1; dx <= 1 ; ++dx) {
            if (i+dx <0 || i+dx >=M.length) continue;
            //for (int dy = -1; dy <= 1 && j+dy>=0 && j+dy <M[0].length; ++dy) {
            for (int dy = -1; dy <= 1; ++dy) {
                if (j + dy < 0 || j+dy >= M[0].length) continue;
                res += M[i+dx][j+dy];
                count++;
            }
        }
        return res/count;
    }
}
