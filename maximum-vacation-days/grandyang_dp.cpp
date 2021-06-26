/*
Runtime: 200 ms, faster than 83.33% of C++ online submissions for Maximum Vacation Days.
Memory Usage: 16.2 MB, less than 0.64% of C++ online submissions for Maximum Vacation Days.
grandyang dp

*/
class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        int n = flights.size(), k = days[0].size(), res = 0;
        vector<vector<int>> dp(n, vector<int>(k, 0));
        for (int j = k - 1; j >= 0; --j) {
            for (int i = 0; i < n; ++i) {
                dp[i][j] = days[i][j];
                for (int p = 0; p < n; ++p) {
                    if ((i == p || flights[i][p]) && j < k - 1) {
                        dp[i][j] = max(dp[i][j], dp[p][j + 1] + days[i][j]);
                    }
                    if (j == 0 && (i == 0 || flights[0][i])) res = max(res, dp[i][0]);
                }
            }
        }
        return res;
    }
};
