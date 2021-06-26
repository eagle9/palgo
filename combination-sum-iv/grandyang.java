/*
grandyang
这道题是组合之和系列的第四道，我开始想当然的一位还是用递归来解，结果写出来发现TLE了，的确OJ给了一个test case为[4,1,2] 32，这个结果是39882198，用递归需要好几秒的运算时间，实在是不高效，估计这也是为啥只让返回一个总和，而不是返回所有情况，不然机子就爆了。而这道题的真正解法应该是用DP来做，解题思想有点像之前爬梯子的那道题Climbing Stairs，我们需要一个一维数组dp，其中dp[i]表示目标数为i的解的个数，然后我们从1遍历到target，对于每一个数i，遍历nums数组，如果i>=x, dp[i] += dp[i - x]。这个也很好理解，比如说对于[1,2,3] 4，这个例子，当我们在计算dp[3]的时候，3可以拆分为1+x，而x即为dp[2]，3也可以拆分为2+x，此时x为dp[1]，3同样可以拆为3+x，此时x为dp[0]，我们把所有的情况加起来就是组成3的所有情况了

beats 54%
*/
class Solution {
    public int combinationSum4(int[] nums, int target) {
        int [] dp = new int[target + 1];
        dp[0] = 1;
        for (int i = 1; i <= target; ++i) {
            for (int j = 0; j < nums.length; j++) {
                if (i >= nums[j]) dp[i] += dp[i - nums[j]];
            }
        }
        return dp[target];
    }
}

/*
如果target远大于nums数组的个数的话，上面的算法可以做适当的优化，先给nums数组排个序，然后从1遍历到target，对于i小于数组中的数字x时，我们直接break掉，因为后面的数更大，其余地方不变，*/
//grandyang idea2, beats 27%
class Solution2 {
    public int combinationSum4(int[] nums, int target) {
        int [] dp = new int[target + 1];
        Arrays.sort(nums);
        
        dp[0] = 1;
        for (int i = 1; i <= target; ++i) {
            
            for (int j = 0; j < nums.length; j++) {
                if (i < nums[j]) break;
                if (i >= nums[j]) dp[i] += dp[i - nums[j]];
            }
        }
        return dp[target];
    }
}
