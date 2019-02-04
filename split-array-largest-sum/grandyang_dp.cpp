//grandyang dp idea, runtime 48ms, faster than 29%
//to understand, Feb 2 2019
//not easy to come up with dp[m][n], m -- number of arrays, n: array from 0 to n-1
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<int> sums(n + 1, 0);
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
        dp[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            sums[i] = sums[i - 1] + nums[i - 1];
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                for (int k = i - 1; k < j; ++k) {
                    int val = max(dp[i - 1][k], sums[j] - sums[k]);
                    dp[i][j] = min(dp[i][j], val);
                }
            }
        }
        return dp[m][n];
    }
};
