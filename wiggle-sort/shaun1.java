/*
grandyang sort and wiggle idea, shaun java code, draw and write number on paper to figure
out the details of the for loop

Runtime: 3 ms, faster than 27.27% of Java online submissions for Wiggle Sort.
Memory Usage: 31.3 MB, less than 0.90% of Java online submissions for Wiggle Sort.

*/
class Solution1 {
    public void wiggleSort(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length; 
        for (int i = 2; i <= n-1; i+=2 ) {
            int temp = nums[i-1];
            nums[i-1] = nums[i];
            nums[i] = temp;
        }
    }
}
/*
grandyang swap idea directly based on the problem requirements, so great idea!
Time is O(n)
Runtime: 0 ms, faster than 100.00% of Java online submissions for Wiggle Sort.
Memory Usage: 25.4 MB, less than 66.47% of Java online submissions for Wiggle Sort.

*/
class Solution {
    public void wiggleSort(int[] nums) {
        for (int i = 0; i <= nums.length-2; i++ ) {
            if ( ( i % 2 == 0 && nums[i] > nums[i+1]) || // should go up, otherwise swap
                (i % 2 == 1 && nums[i] < nums[i+1])) { // should go down, otherwise swap
                int temp = nums[i];
                nums[i] = nums[i+1];
                nums[i+1] = temp;
            }            
        }
        
    }
}
