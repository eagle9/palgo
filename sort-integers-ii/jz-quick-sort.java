//use jz solution/quicksort, Your submission beats 91.80% Submissions!
//this quick sort use two way partition
import java.util.Random;

public class Solution {
    /*
     * @param A: an integer array
     * @return: 
     */
    public Random rand;
    public void sortIntegers2(int[] A) {
        rand = new Random();
        // write your code here
        quickSort(A, 0, A.length - 1);
    }
    
    public void quickSort(int[] A, int start, int end) {
        if (start >= end) {
            return;
        }
        //Returns a pseudorandom, uniformly distributed int value between 0 (inclusive) and the specified value (exclusive), drawn from this random number generator's sequence.
        int index = rand.nextInt(end - start + 1)  + start; //at max it is end - start = start = end
        int pivot = A[index];
        int left = start;
        int right = end;
       
        while (left <= right) {
            //left going right when A < pivot, trying to extend left part < pv
            while (left <= right && A[left] < pivot) {
                left ++;
            }
            //right going left when A > pivot, trying to extend right part > pv
            while (left <= right && A[right] > pivot) {
                right --;
            }
            
            if (left <= right) {  //left <= right, found left part and right part violators, swap
                int temp = A[left];
                A[left] = A[right];
                A[right] = temp;
                
                left ++;
                right --;
                //continue to extend left and right zone
            } 
        }
        //exit: start ... right < left ... end
        quickSort(A, start, right); //sort left part 
        quickSort(A, left, end); //sort right part 
    }
}
