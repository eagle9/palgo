//shaun's idea for diagonal check, based on grandyang idea1 brutal force
//runtime 13ms, faster than 90%
class Solution {
    public int longestLine(int[][] M) {
        if (M == null || M.length ==0) return 0;
        int res = 0, m = M.length, n = M[0].length;
        for (int i = 0; i < m; i++) { //go horizontal for each row
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (M[i][j] == 1) res = Math.max(res,++cnt);
                else cnt = 0;
            }
        }
        
        for (int j = 0; j < n; j++) { //vertical for each column
            int cnt = 0;
            for (int i = 0; i < m; i++) {
                if (M[i][j] == 1) res = Math.max(res, ++cnt);
                else cnt = 0;
            }
        }
        
        int [][] start = new int[m+n-1][2];
        //  \diagonal determine start
        for (int k = 0; k < start.length; k++) {
            if (k <= m-1)
                start[k][0] = m-1-k;
            else
                start[k][1] = k-m+1;
        }
        //  \diagonal check line
        for (int k = 0; k < start.length; k++) {
            //y is row, and x is col
            int y = start[k][0], x = start[k][1];
            int cnt = 0;
            for ( ; x < n && y < m; x++,y++) {
                if (M[y][x] ==1) res = Math.max(res,++cnt);
                else cnt = 0;
            }
        }
        ///   / diagonal determine start
        for (int k = 0; k < start.length; k++) {
            if (k <= n-1) {
                start[k][0] = 0;
                start[k][1] = k;
            }
            else { //k >=n
                start[k][0] = k-n+1;
                start[k][1] = n-1;
            }    
            
        }
        //  /diagonal check line
        for (int k = 0; k < start.length; k++) {
            //y is row, x is col
            int y = start[k][0], x = start[k][1];
            int cnt = 0;
            for ( ; x >=0 && y < m ; x--,y++) {
                if (M[y][x] ==1) res = Math.max(res,++cnt);
                else cnt = 0;
            }
        }
        
        return res;
        
    }
}

