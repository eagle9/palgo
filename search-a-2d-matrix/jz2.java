// Binary Search Once, beats 100.00%
public class Solution {
    /**
     * @param matrix, a list of lists of integers
     * @param target, an integer
     * @return a boolean, indicate whether matrix contains target
     */
    public boolean searchMatrix(int[][] matrix, int target) {
        // write your code here
        if(matrix == null || matrix.length == 0){
            return false;
        }
        
        if(matrix[0] == null || matrix[0].length == 0){
            return false;
        }
        
        //treat the matrix as 1 single array
        int row = matrix.length;
        int column = matrix[0].length;
        
        int start = 0, end = row * column - 1;
        /*
        while(start <= end){
            int mid = start + (end - start) / 2;
            int number = matrix[mid / column][mid % column];
            if(number == target){
                return true;
            }else if( target < number){ //first half
                end = mid - 1;
            }else{ //target > number  //second half
                start = mid + 1;
            }
        }
        
        //start > end
        return false;
        */
        while (start + 1 < end) {
            int mid = (start + end)/2;
            int number = matrix[mid/column][mid % column];
            if (number == target) {
                return true;
            }else if (target < number) { //first half
                end = mid - 1;
            }else {
                start = mid+ 1;
            }
        }
        //start +1 ==end
        if (matrix[start / column][start % column] == target) return true;
        if (matrix[end/column][end % column] == target) return true;
        return false;
        
    }
}
