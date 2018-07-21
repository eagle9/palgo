public class Solution {
    /**
     * @param nums an integer array
     * @return nothing, do this in-place
     */
     //jiuzhang, Your submission beats 75.00% Submissions!
    //same idea as jiadai, different coding
    public void moveZeroes(int[] nums) {
        // Write your code here
        int left = 0, right = 0;
        while (right < nums.length) {
            if (nums[right] != 0) {
                int temp = nums[left];
                nums[left] = nums[right];
                nums[right] = temp;
                left++;
            }
            right++;
        }
    }
}
