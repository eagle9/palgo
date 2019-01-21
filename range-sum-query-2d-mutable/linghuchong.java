//grandyang idea, linghuchong java code, runtime 76ms, faster than 100%
//
public class NumMatrix {
    private int[][] arr, bit;
    int n, m;
    
    /**
     * @return: nothing
     */
    public NumMatrix(int[][] matrix) {
        n = matrix.length;
        //shaun added n > 0 test, otherwise matrix[0] index out of bound exception. anytime you use an index, make sure it is in bound.
        if (n >0 ) {
            m = matrix[0].length;
            arr = new int[n][m];
            bit = new int[n + 1][m + 1];

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    update(i, j, matrix[i][j]);
                }
            }
        }
    }
    
    public void update(int row, int col, int val) {
        int delta = val - arr[row][col];
        arr[row][col] = val;
        
        for (int i = row + 1; i <= n; i = i + lowbit(i)) {
            for (int j = col + 1; j <= m; j = j + lowbit(j)) {
                bit[i][j] += delta;
            }
        }
    }
    
    public int sumRegion(int row1, int col1, int row2, int col2) {
        /*   1  B
             A  2
                      
                   r1,c1     
                            row2,col2
        */
        int res = 
            prefixSum(row2, col2)
            - prefixSum(row2, col1 - 1) //rectangle 1A
            - prefixSum(row1 - 1, col2) //rectangle 1B
            + prefixSum(row1 - 1, col1 - 1);  //rectangle 1
        return res;
    }
    
    private int prefixSum(int row, int col) {
        int sum = 0;
        for (int i = row + 1; i > 0; i = i - lowbit(i)) {
            for (int j = col + 1; j > 0; j = j - lowbit(j)) {
                sum += bit[i][j];
            }
        }
        return sum;
    }
    
    private int lowbit(int x) {
        return x & (-x);
    }
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * obj.update(row,col,val);
 * int param_2 = obj.sumRegion(row1,col1,row2,col2);
 */
