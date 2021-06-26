//https://pobenliu.gitbooks.io/leetcode/Maximum%20Subarray%20III.html
//beats 91.40%
public class Solution {
    /**
     * @param nums: A list of integers
     * @param k: An integer denote to find k non-overlapping subarrays
     * @return: An integer denote the sum of max k non-overlapping subarrays
     */
    public int maxSubArray(int[] nums, int k) {
        if (nums == null || nums.length == 0 
            || k <= 0 || k > nums.length) {
            return -1;
        }

        int n = nums.length;
        // status
        int[][] globalMax = new int[n + 1][k + 1];
        int[][] localMax = new int[n + 1][k + 1];
        // initialize

        for (int j = 1; j <= k; j++) {
            localMax[j - 1][j] = Integer.MIN_VALUE;
            for (int i = j; i <= n; i++) {
                localMax[i][j] = Math.max(localMax[i - 1][j], globalMax[i - 1][j - 1]) + nums[i - 1];
                if (i == j) {
                    globalMax[i][j] = localMax[i][j];
                } else {
                    globalMax[i][j] = Math.max(globalMax[i - 1][j], localMax[i][j]);   
                }
            }
        }

        return globalMax[n][k];
    }

}
