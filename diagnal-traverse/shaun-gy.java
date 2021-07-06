/*
shaun down idea
slide down, slide left, slide up, slide right
but grandyang has cleaner code
0,0
1,-1(out bound)
dx=1, dy=-1
turn around, slide down
  1,0  ---->2
  dx=-1, dy=1
  0,1 ----> 4
  -1,2 (ob)
  slide back to left, reverse dx dy, dx=1, dy=-1
  0,2 ---> 7
  1,1 -----5
  2,0 --- 3 
*/
class Solution {
    public int[] findDiagonalOrder(int[][] mat) {
        //if (mat.length == 0 || mat[0].length == 0) return {};
        int m = mat.length, n = mat[0].length;
        // row and column for each i from 0 to m*n
        // start from 0 0
        int r = 0, c = 0;
        int k = 0;
        int [] res = new int[m * n];
        //delta: down,  up
        int [][] delta = {{-1,1}, {1,-1}};
        for (int i = 0; i < m * n; ++i) {
            res[i] = mat[r][c];
            r += delta[k][0];
            c += delta[k][1];
            //ob down
            if (r >= m) { //over bottom edge
                r = m - 1;  //back
                c += 2; // go right by 2
                k = 1 - k; //switch delta
            }
            if (c >= n) { //over right edge
                c = n - 1; //g
                r += 2;
                k = 1 - k;
            }
            if (r < 0) { //over top edge
                r = 0; k = 1 - k;
            }
            if (c < 0) { //over left edge
                c = 0; k = 1 - k;
            }
        }
        return res;
    }
}
