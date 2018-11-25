public class Solution {
    /**
     * @param n: An integer
     * @param nums: An array
     * @return: the Kth largest element
     */
    public int kthLargestElement(int k, int[] nums) {
        // write your code here
        
        //key point 1: kth largest --> len - k th rank
        return quickSelect2(nums, 0, nums.length-1, nums.length -k);
    }
    
    //key point 1: kth largest sorted index is len - k
    //10 numbers: 1, 2, 3, ..., 10, 3rd largest is 8, sorted index is 7 = 10-3, 0...7 
    
    //key point 2: use partition
    int partition(int []nums, int start, int end) {
        
        int mid = (start + end)/2;
        int temp = nums[mid];
        nums[mid] = nums[end];
        nums[end] = temp;
        int pivot = nums[end];
        
        int index = start -1;
        for (int j = start; j <= end; j++) {
            if (nums[j] < pivot) {
                index++;
                temp = nums[index];
                nums[index] = nums[j];
                nums[j] = temp;
            }
        }
        index++;
        temp = nums[index];
        nums[index] = nums[end];
        nums[end] = temp;
        return index;
    }
    //finally get my idea to work, beats 84.00%
    //key point, it is different from quicksort, you have to include pivot
    private int quickSelect2(int [] nums, int start, int end, int k) {
        if (start == end)
            return nums[end];
        int index =  partition(nums,start,end);
        if (index == k)
            return nums[index];
        if (k <= index)
            return quickSelect2(nums, start, index,k);
        else 
            return quickSelect2(nums, index+1, end,k);
    }
    
    //it is not directy use of quicksort
    //beats 77.60%, but not clear about several details
    private int quickSelect(int [] nums, int start, int end, int k) {
        //miss point 1, why? 
        if (start == end)
            return nums[end];
            
        
        int left = start, right = end;
        
        int mid = (start + end) /2;
        int pivot = nums[mid];
        
        while (left <= right) {
            while (left <= right && nums[left] < pivot) 
                left++;    
            while (left <= right && nums[right] > pivot)
                right--;
            if (left <= right) {
                int temp = nums[left];
                nums[left] = nums[right];
                nums[right] = temp;
                
                //why this condition
                if (left < end)
                    left++;
                //why this condition
                if (right > start)    
                    right--;
            }
        }
        //left > right
        
            
        if (k <= right)
            return quickSelect(nums,start,right,k);
        else 
            return quickSelect(nums,right+1,end,k);
            //return quickSelect(nums,left, end, k);// does not work
    }
}
