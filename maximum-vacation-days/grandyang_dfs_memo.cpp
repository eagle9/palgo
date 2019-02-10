/*
Runtime: 216 ms, faster than 72.22% of C++ online submissions for Maximum Vacation Days.
Memory Usage: 16.3 MB, less than 0.64% of C++ online submissions for Maximum Vacation Days.
grandyang dfs with memo

*/
class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        int n = flights.size(), k = days[0].size();
        vector<vector<int>> memo(n, vector<int>(k, 0));
        return helper(flights, days, 0, 0, memo);
    }
    int helper(vector<vector<int>>& flights, vector<vector<int>>& days, int city, int day, vector<vector<int>>& memo) {
        int n = flights.size(), k = days[0].size(), res = 0;
        if (day == k) return 0;
        if (memo[city][day] > 0) return memo[city][day];
        for (int i = 0; i < n; ++i) {
            if (i == city || flights[city][i] == 1) {
                res = max(res, days[i][day] + helper(flights, days, i, day + 1, memo));
            }
        }
        return memo[city][day] = res;
    }
};
