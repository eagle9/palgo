//lt binary search, shaun came up with binary search rough idea, deep read the code and modified to my own idea 
//runtime 1ms, faster than 99%, mem less than 78%
public class Solution {
    public int minArea(char[][] image, int x, int y) {
        int m = image.length, n = image[0].length;
        //find left in [0,y]
        int left = searchColumns(image, 0, y, 0, m, true);
        int right = searchColumns(image, y + 1, n, 0, m, false); //right most black +1
        int top = searchRows(image, 0, x, left, right, true);
        int bottom = searchRows(image, x + 1, m, left, right, false); //lowest black + 1
        return (right - left) * (bottom - top);
    }
    private int searchColumns(char[][] image, int i, int j, int top, int bottom, boolean goSmall) {
        
        while (i != j) {
            int mid = (i + j) / 2;
            //column mid has 1?
            boolean hasBlack = false;
            for (int k = top; k < bottom; ++k) {
                if (image[k][mid] == '1') {
                    hasBlack = true;
                    break;
                }
            }
            
            //draw a picture,   goSmall && black, go small; white && goSmall, go up 
            if (goSmall) { //i == j exit, i == black
                if (hasBlack) j = mid; //search the boundary in the smaller half, j reduced
                else i = mid + 1;//search the boundary in the greater half, i incrased
            }else {   // i==j 1 after black
                if (hasBlack) i = mid + 1;
                else j = mid;
            }
            
        }
        //i == j now
        return i;
    }
    private int searchRows(char[][] image, int i, int j, int left, int right, boolean goSmall) {
        while (i != j) {
            int mid = (i + j) / 2;
            //mid row has 1 pixel???
            boolean hasBlack = false;
            for (int k = left; k< right; ++k) {
                if (image[mid][k] == '1') {
                    hasBlack = true;
                }
            }
            //draw a picture,   goSmall && black, go small; white && goSmall, go up 
            if (goSmall) { //i == j exit, i == black
                if (hasBlack) j = mid; //search the boundary in the smaller half, j reduced
                else i = mid + 1;//search the boundary in the greater half, i incrased
            }else {   // i==j 1 after black
                if (hasBlack) i = mid + 1;
                else j = mid;
            }
        }
        return i;
    }
}
