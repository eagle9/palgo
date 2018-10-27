//shaun's own code, two pointer idea, beats 84.20%

public class Solution {
    /**
     * @param nums: a list of integers.
     * @param k: length of window.
     * @return: the sum of the element inside the window at each moving.
     */
    public int[] winSum(int[] nums, int k) {
        // forgot the corner case
        if (nums == null || nums.length ==0)
            return new int[0];
        int n = nums.length;
        int rlen = n - k + 1;
        int [] res = new int[rlen];
        int right = 0;
        int sum = 0;
        while (right < k) {
            sum += nums[right++];
            
        }
        //right == k now
        int index = 0;
        res[index++] = sum;
        
        while (right < n) {
            int left = right -k;
            sum -= nums[left];
            sum += nums[right++];
            res[index++] = sum;
        }
        return res;
    }
}
