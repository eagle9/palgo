public class Solution {
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    //jz beats 62.60%, not use Math.max, beats 90.00%
    /*
    public int maxSubArray(int[] nums) {
        // write your code here
        int res = Integer.MIN_VALUE, curSum = 0;
        for (int i  = 0; i < nums.length; i++) {
            curSum += nums[i];
            //instead of using Math.max(a,b)
            curSum = curSum > nums[i]? curSum : nums[i];
            res = res> curSum? res: curSum;
        }
        return res;
    }
    */
    
    //jiadai c++ -> shaun java, beats 98.20%
    //iterate from 1
    /*
    public int maxSubArray0(int [] nums) {
        int sum = nums[0];
        int maxSum = nums[0];
        int n  = nums.length;
        for (int i = 1; i < n; ++i) {
            if (sum < 0)  //this is key to reset sum
                sum = nums[i];
            else 
                sum += nums[i];
            maxSum =maxSum> sum? maxSum: sum;
        }
        return maxSum;
    }*/
    //jiadai c++ -> java, start from 0, this can be used in maximum subarray ii
    //beats 88.40%
    public int maxSubArray(int [] nums) {
        int sum = 0;
        int maxSum = Integer.MIN_VALUE;
        int n  = nums.length;
        for (int i = 0; i < n; ++i) {
            if (sum < 0)  //this is key to reset sum
                sum = nums[i];
            else 
                sum += nums[i];
            maxSum =maxSum> sum? maxSum: sum;
        }
        return maxSum;
    }
    
}
