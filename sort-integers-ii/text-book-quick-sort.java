public class Solution {
    /**
     * @param A: an integer array
     * @return: nothing
     */
    public void sortIntegers2(int[] A) {
        // write your code here
        quickSort(A, 0, A.length-1);
    }
    
    private Random rand = new Random();
    //shaun's own from memory, beats 86.20% with pivot at mid
    //beats 99.20% with Random nextInt
    //quckSort partition with two pointers 
    private void quickSort1(int [] A,int start, int end) {
        //since it is recursive call, don't forget the exit condition
        if (start >= end)
            return;
            
        int left = start, right = end;
        //int mid = (left + right)/2;
        int mid = left + rand.nextInt(right-left);
        int pivot  = A[mid];
        //partition
        while (left <= right) {
            while (left <= right && A[left] < pivot)
                left++;
            while (left <= right && A[right] > pivot)
                right--;
            if (left <= right) {  //left > pivot, right < pivot
                int temp = A[left];
                A[left] = A[right];
                A[right] = temp;
                left++;
                right--;
            }
        }
        
        //left > right now, divide and conquer
        quickSort(A,start,right);
        quickSort(A,left,end);
    }
    
    //textbook version, during partition, find all e < pivot and put them before pivot
    //beats 100.00%
    //three key points: 1) choose a pivot any where from start to end, and swap pivot with the end; 2) count and find all e < pivot, and put e before pivot; 3) put pivot at its deserved position
    
    private void quickSort(int [] A, int start, int end) {
        if (start >= end)
            return;
        //int mid = (start + end)/2;
        int mid = rand.nextInt(end - start) + start;
        int temp = A[mid];
        A[mid] = A[end];
        A[end] = temp;
        
        int pivot = A[end];
        
        //partition A  the number of elements < pivot is i
        //  all < elements before pivot
        // all >= elements after pivot
        int index = start -1;
        for (int j = start; j <= end; j++) {
            if (A[j] < pivot) {
                index++;
                temp = A[index];
                A[index] = A[j];
                A[j] = temp;
            }
        }
        //place pivot value at index
        index++;
        //swap index and end
        temp = A[index];
        A[index] = pivot;
        A[end] = temp;
        
        quickSort(A,start,index-1);
        quickSort(A,index+1, end);
    }
}
