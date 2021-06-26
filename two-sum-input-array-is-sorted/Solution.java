public class Solution {
    /**
     * @param nums: an array of Integer
     * @param target: target = nums[index1] + nums[index2]
     * @return: [index1 + 1, index2 + 1] (index1 < index2)
     */
     //based on jiadai c++
    public int[] twoSum(int[] nums, int target) {
        // write your code here
        int [] result = new int[2];
        int start = 0, end = nums.length - 1;
        while (start < end) {
            if (nums[start] + nums[end] == target) {
                result[0] = start + 1;
                result[1] = end + 1;
                return result;
            }
            if (nums[start] + nums[end] > target) {
                end--; //go smaller
            }else {
                start++; //go larger
            }
        }
        return result;
    }
}
