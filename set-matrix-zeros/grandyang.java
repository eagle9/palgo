//grandyang idea, use col 0 and row 0 to store info, space is O(1)
//you can not update on the fly, update simultaneously, which is the key
//runtime 1ms, faster than 100%
//with csinpiration video, 1/26/2019
class Solution2 {
    public void setZeroes(int[][] matrix) {
        if (matrix == null || matrix.length == 0 ) return;
        int m = matrix.length, n = matrix[0].length;
        //solve matrix [1 .. m] [1 ..n] first with matrix[0][] and matrix[][0]
        boolean rowZero = false, colZero = false;
        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] == 0) colZero = true;
        }
        for (int i = 0; i < n; ++i) {
            if (matrix[0][i] == 0) rowZero = true;
        } 
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[0][j] == 0 || matrix[i][0] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (rowZero) {
            for (int i = 0; i < n; ++i) matrix[0][i] = 0;
        }
        //what the actitive for false? 
        if (colZero) {
            for (int i = 0; i < m; ++i) matrix[i][0] = 0;
        }
    }
}
//shaun idea, use space O(m+n), runtime 1ms and faster than 100%
class Solution {
    public void setZeroes(int[][] matrix) {
        if (matrix == null || matrix.length == 0 ) return;
        int m = matrix.length, n = matrix[0].length;
        //use space O(m+n)
        boolean [] rowZero = new boolean [m], colZero = new boolean [n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    rowZero[i] = true;
                    colZero[j] = true;
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (rowZero[i] || colZero[j]) matrix[i][j] = 0;
            }
        }
        
    }
}
