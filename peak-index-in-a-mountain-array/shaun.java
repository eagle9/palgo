class Solution {
    //https://nifannn.github.io/2018/06/29/%E7%AE%97%E6%B3%95%E7%AC%94%E8%AE%B0-Leetcode-852-Peak-Index-in-a-Mountain-Array/
    //binary search, beats 75%, O(lgn)
    public int peakIndexInMountainArray(int[] A) {
        int left = 0;
        int right = A.length - 1;
        
        while(left < right){
            int mid = left + (right - left) / 2;
            if(A[mid-1] < A[mid] && A[mid] > A[mid+1]){ return mid; }
            if(A[mid-1] < A[mid] && A[mid] < A[mid+1]){ left = mid + 1; }
            // based on the assumption, else means mid is on down slope
            else{ right = mid - 1; }
        }
        //left == right
        //return left;  //okay
        return right; //okay too
    }
}
//simple solution, beats 75%, O(n)
class Solution1 {
    public int peakIndexInMountainArray(int[] A) {
        int i = 0;
        while(A[i] < A[i+1]){ i++; }
        //ai >= a i+1
        return i;
    }
}
