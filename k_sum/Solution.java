//adpated from jiadai c++,Your submission beats 100.00% Submissions!
class Solution {
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return an integer
     */
    public int kSum(int[] A, int k, int target) {
        // wirte your code here
        int n = A.length;
        int[][] dp = new int[1 + k] [1 + target];
        dp[0][0] = 1;

        for (int i = 0; i < n; ++i) {
            for (int j = k; j >= 1; --j) {
                for (int t = target; t >= A[i]; --t) {
                    dp[j][t] += dp[j - 1][t - A[i]];
                }
            }
        }

        return dp[k][target];
    }
};
