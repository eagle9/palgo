/*
runtime 111ms, faster than 74%
grandyang idea1, dp
这道题让我们检索一个数组的某个区间的所有数字之和，题目中给了两条条件，首先数组内容不会变化，其次有很多的区间和检索。那么我们用传统的遍历相加来求每次区间和检索，十分的不高效，而且无法通过OJ。所以这道题的难点就在于是否能想到来用建立累计直方图的思想来建立一个累计和的数组dp，其中dp[i]表示[0, i]区间的数字之和，那么[i,j]就可以表示为dp[j]-dp[i-1]，这里要注意一下当i=0时，直接返回dp[j]即可

*/
class NumArray {

    public NumArray(int[] nums) {
        dp = new int[nums.length];
        if (nums.length > 0) {
            dp[0] = nums[0];
        }
        for (int i = 1; i < nums.length; i++) {
            dp[i] += nums[i] + dp[i-1];
        }
    }
    
    public int sumRange(int i, int j) {
        return i == 0? dp[j] : dp[j] - dp[i-1];
    }
    private int [] dp;
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
