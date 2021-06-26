public class Solution {
    /**
     * @param nums: an array of integer
     * @param target: An integer
     * @return: An integer
     */
     //adapted from jiadai c++
     //Your submission beats 18.40% Submissions! low, how come? c++ is better
    public int twoSum6(int[] nums, int target) {
        // write your code here
        if (nums.length == 0)
            return 0; //no pair will be found if nums is empty
        Arrays.sort(nums);
        int start = 0, end = nums.length - 1;
        int count = 0;
        while (start < end) {
            if (nums[start] + nums[end] < target) {
                start++;
            }else if (nums[start] + nums[end] > target) {
                end--;
            }else { // ==  target 
                start++;
                end--;
                count++; //found 1
                //now look for different number
                while (start < end && nums[start] == nums[start-1])
                    start++;
                while (start < end && nums[end] == nums[end+1])
                    end--;
            }
        }
        return count;
        
    }
}
