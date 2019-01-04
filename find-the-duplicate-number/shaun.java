//shaun own idea, beats 48%
//same idea as what is used in find all duplicated number in a array, and find all disappearred number
class Solution {
    public int findDuplicate(int[] nums) {
        int res = 0;
        for (int i = 0; i < nums.length; i++) {
            
            int v = nums[i];
            if (nums[i] != nums[v-1]) {
                swap(nums, i, v-1);
                i--;
            }
            
        }
        
        for (int i = 0; i < nums.length; i++) {
            int v = nums[i];
            if (nums[i] != i+1) return nums[i];
        }
        
        return res;
    }
    private void swap(int [] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}
