/*
shaun 2nd round, write from idea, and accepted after adding n==0 case 

dynamic programming and dp array dimension reduced. 
Feb 13 2019

Runtime: 3 ms, faster than 89.63% of Java online submissions for House Robber.
Memory Usage: 36.9 MB, less than 100.00% of Java online submissions for House Robber.
*/
class Solution {
    public int rob(int[] nums) {
        
        int n = nums.length; 
        if (n == 0) return 0;
        
        //int [] dp = new int[n];
        if (n == 1) return nums[0];
        if (n == 2) return Math.max(nums[0], nums[1]);
        //now n>= 3
        //dp[0] = nums[0];
        //dp[1] = Math.max(nums[0], nums[1]);
        int first = nums[0], second = Math.max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            //rob house i-1, can not rob house i
            //house i-1 not robbed, rob house i
            //dp[i] = Math.max(dp[i-1], dp[i-2] + nums[i]);
            int temp = Math.max(second, first + nums[i]);
            first = second;
            second = temp;
            
        }
        //return dp[n-1];
        return second;
    }
}
