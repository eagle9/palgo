//grandyang idea1, 59ms, faster than 4%, not understood
class Solution {
    public int maximalSquare(char[][] matrix) {
        int res = 0;
        int m = matrix.length;
        
        
        for (int i = 0; i < m; ++i) {
            int n = matrix[i].length;
            int [] v = new int[n];
            for (int j = i; j < m; ++j) {
                for (int k = 0; k < matrix[j].length; ++k) {
                    if (matrix[j][k] == '1') ++v[k];
                }
                res = Math.max(res, getSquareArea(v, j - i + 1));
            }
        }
        return res;
    }
    private int getSquareArea(int []v, int k) {
        if (k > v.length) return 0;
        int count = 0;
        for (int i = 0; i < v.length; ++i) {
            if (v[i] != k) count = 0; 
            else ++count;
            if (count == k) return k * k;
        }
        return 0;
    }
}
