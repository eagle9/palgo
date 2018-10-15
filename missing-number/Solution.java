public class Solution {
    /**
     * @param nums: An array of integers
     * @return: An integer
     */
     //using sort and binary search, find the first A[i] != i. beats 87%
     //time complexity is n(logn ) because of the sorting
    public int findMissing1(int[] A) {
        int len = A.length;
        Arrays.sort(A);
        int left = 0, right = len - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (A[mid] > mid) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return A[left] == left ? left + 1 : left;
    }
    
    
    //time complexty is O(n) and space is O(1)
    //beats 88.20%
    public int findMissing2(int[] A) {
        int len = A.length;
        int sum = 0;
        for (int i = 0; i < len; i++) {
            sum += A[i];
        }
        //0, 1, 2,...,len, total len+1 numberï¼Œone extra number == len
        int targetsum = len * (len + 1) / 2; 
        return targetsum - sum;
    }
    
    public int findMissing(int[] nums) {
        int x = 0;
        for (int i = 0; i <= nums.length; i++) {
            x ^= i;
        }
        for (int i = 0; i < nums.length; i++) {
            x ^= nums[i];
        }
        return x;
    }
    

}
