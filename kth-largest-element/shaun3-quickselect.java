/*
Runtime: 7 ms, faster than 28.26% of Java online submissions for Kth Largest Element in an Array.

accepted with many bug fixes
partition left >= pivot >= right, pick left as pivot
pick right causing problem
*/
class Solution {
    public int findKthLargest(int[] nums, int k) {
        return helper(nums, 0, nums.length-1, k-1);
    }
    
    private int helper(int [] nums, int left, int right, int k) {
        if (left >= right) return nums[left];
        //now left < right
        int ip = partition(nums, left, right);
        if (ip == k) {
            return nums[ip];
            
        }
        if (ip < k) {
            return helper(nums, ip+1,right,k);  //ip -> ip+1 bug fix
        } 
        else
            return helper(nums,left, ip-1, k);  //ip -> ip-1 bug fix
        
    }
    
    /*
   
    */
    
    private int partition(int [] nums,int left,int right) {
        //last element value as pivot
        int pivotVal = nums[left];
        int i = left+1, j = right;
        while (i < j) {
            while (nums[i] >= pivotVal && i < j) i++;
            while (nums[j] <= pivotVal && i < j) j--;
            if (i < j ) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                i++;
                j--;
            }
        }
        //i == j now
        int ip = i;
        if (nums[i] < nums[left]) {  //bug fix
            ip--;
        }
        //swap ip with pivot
        int temp = nums[left];
        nums[left] = nums[ip];
        nums[ip] = temp;
        return ip;
    }
}
