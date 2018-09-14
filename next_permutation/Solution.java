//jz, Your submission beats 99.60% Submissions!
public class Solution {
    /**
     * @param nums: A list of integers
     * @return: A list of integers that's next permuation
     */
    public void swapItem(int[] nums, int i, int j) {
    	int temp = nums[i];
		nums[i] = nums[j];
		nums[j] = temp;
	}
	public void swapList(int[] nums, int i, int j) {
		while (i < j) {
			swapItem(nums, i, j);
			i ++; j --;
		}
	}
    public int[] nextPermutation(int[] nums) {
		int len = nums.length;
		if ( len <= 1)
			return nums;
		int i = len - 1;
		while (i > 0 && nums[i] <= nums[i - 1])
			i --;
		swapList(nums, i, len - 1);
		if (i != 0) {
			int j = i;
			while (nums[j] <= nums[i - 1]) j++;
			swapItem(nums, j, i-1);
		}
		return nums;
    }
}
