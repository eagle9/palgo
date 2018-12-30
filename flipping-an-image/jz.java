class Solution1 {
    //beats 17%, shaun own idea and java code
    public int[][] flipAndInvertImage(int[][] A) {
        int ROWS = A.length;
        int COLS = A[0].length;
        for (int i = 0; i < ROWS; i++) {
            //flip an image horizontally 
            //0 <-> COLS-1
            //1 <-> COLS-1-1
            for (int j = 0; j < COLS/2; j++) {
                int temp = A[i][j];
                A[i][j] = A[i][COLS-1-j];
                A[i][COLS-1-j] = temp;
            }
            //invert
            for (int j = 0; j < COLS; j++) {
                A[i][j] = A[i][j]>0? 0: 1;
            }
        }
        return A;
    }
}
class Solution {
    //beats 36%, shaun own idea and java code
    public int[][] flipAndInvertImage(int[][] A) {
        int M = A.length, N = A[0].length;
        int [][] res = new int[M][N];
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                res[i][j] = 1 - A[i][N - 1 - j];
            }
        }
        return res;
    }
}
