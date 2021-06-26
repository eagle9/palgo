public class Solution {
    
    //grandyang idea, shaun java code from translate, modified for more natural understanding,  beats 98%
    public int rob(int [] nums) {
        int n = nums.length;
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        //two choices for a circile street
        // choice 1: rob 0 to n-2
        // choice 2: rob 1 to n-1
        return Math.max(rob(nums, 0, n-2), rob(nums, 1, n-1));
    }
    int rob(int [] nums, int left, int right) {
        if (right == left) return nums[left];
        int [] dp = new int[nums.length];
        
        dp[left] = nums[left];
        dp[left + 1] = Math.max(nums[left], nums[left + 1]);
        for (int i = left + 2; i <= right; ++i) {
            dp[i] = Math.max(nums[i] + dp[i - 2], dp[i - 1]);
        }
        return dp[right];
    }
};
