//jiuzhang, Your submission beats 94.80% Submissions!
//use swap function, beats 99.40%, also code simpler
//same idea as jiadai, different coding, shaun modified for easier understanding
//index and swap part similar to quicksort
//beats 50% at leetcode
public class Solution {
    /**
     * @param nums an integer array
     * @return nothing, do this in-place
     */
    public void moveZeroes(int[] nums) {
        int indexNonZ = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != 0) {
                /*
                if (i != indexNonZ) {
                    int temp = nums[indexNonZ];
                    nums[indexNonZ] = nums[i];
                    nums[i] = temp;
                }
                indexNonZ++;
                */
                swap(nums,indexNonZ++,i);
            }
        }
    }
    private void swap(int [] nums, int i, int j) {
        if (i != j) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
    }
    
}
