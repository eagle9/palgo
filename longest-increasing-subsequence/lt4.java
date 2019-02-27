/*
lt4, dp with binary search
Runtime: 1 ms, faster than 94.58% of Java online submissions for Longest Increasing Subsequence.
Memory Usage: 37.6 MB, less than 30.68% of Java online submissions for Longest Increasing Subsequence.
*/
public class Solution {
    public int lengthOfLIS(int[] nums) {
        int[] dp = new int[nums.length];
        int len = 0;
        for (int num : nums) {
            int i = Arrays.binarySearch(dp, 0, len, num);
            if (i < 0) {
                i = -(i + 1);
            }
            dp[i] = num;
            if (i == len) {
                len++;
            }
        }
        return len;
    }
}
