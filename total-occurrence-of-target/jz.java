//jz beats 86.00%
public class Solution {
    /**
     * @param A an integer array sorted in ascending order
     * @param target an integer
     * @return an integer
     */
    public int totalOccurrence(int[] A, int target) {
        // Write your code here
        int n = A.length;
        if (n == 0) {
            return 0;
        }
        if (target < A[0] || A[n-1] < target ) { //target out of range
            return 0;
        }
        
        int left = 0, right = n - 1;
        int front = 0; //what does start stand for?  front index that match target
        while (left <= right) { // left == right, nothing in between
            int mid = (left + right)/ 2;
            if (target <= A[mid]) { //trying to find target in front part
                front = mid;
                right = mid - 1;
            } else
                left = mid + 1;
        }
        //exit while loop: left > right
        if (A[front] != target)
            return 0;

        int back = n - 1;
        left = 0; right = n - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (A[mid] <= target) { //trying to find target in back part
                back = mid;
                left = mid + 1;
            } else
                right = mid - 1;
        }
        return back - front + 1;
    }
}
