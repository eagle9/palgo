/*

1 pass O(n) comparisons to partition the array
partition(left, right) return pivot index
left .. pivot-1   <= pivot <= pivot +1

*/
class Solution {
    public int[] sortArray(int[] nums) {
        int [] a = Arrays.copyOf(nums,nums.length); 
        helper(0, a.length-1,a);//bug length --> length-1
        return a;
    }
    private void helper(int left, int right, int [] nums) {
        if (left >= right) return;
        //when left < right 
        int ip = partition(left,right,nums);
        helper(left, ip-1,nums);
        helper(ip+1,right,nums);
    }
    
    //left < right always, ensured before call
    
    /*
    5 1 2 3
    i.  j pv
    2   5
      ij
    2   
    test driven coding with example
    accepted with 1 minor bug fix
    Runtime: 3 ms, faster than 99.50% of Java online submissions for Sort an Array.
Memory Usage: 47.1 MB, less than 6.12% of Java online submissions for Sort an Array.
    */
    private int partition(int left,int right, int [] nums) {
        //last element value as pivot
        int pivotVal = nums[right];
        int i = left, j = right-1;
        while (i < j) {
            while (nums[i] <= pivotVal && i < j) i++;
            while (nums[j] >= pivotVal && i < j) j--;
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
        if (nums[i] < pivotVal) {
            ip++;
        }
        //swap ip with pivot
        int temp = nums[right];
        nums[right] = nums[ip];
        nums[ip] = temp;
        return ip;
    }
}
