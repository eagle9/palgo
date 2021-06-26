//Your submission beats 95.52% Submissions!
//http://www.cnblogs.com/grandyang/p/5677550.html


class Solution {
public:
    int getMoneyAmount(int n) {
        //dp[j][i] stores the money needed from j to i
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        
        // i is the end of range, from 2 to n
        for (int i = 2; i <= n; ++i) {
            //j is the start of range, from 1 to n-1
            for (int j = i - 1; j > 0; --j) { 
                int global_min = INT_MAX;
                //k from j+1 to i-1
                for (int k = j + 1; k < i; ++k) { //guess k between j and i
                    //work on the recurrence
                    int local_max = k + max(dp[j][k - 1], dp[k + 1][i]);
                    global_min = min(global_min, local_max);
                }
                //j+1 = i case not covered by for k loop
                //but dp[j,j+1] = j
                dp[j][i] = j + 1 == i ? j : global_min;
                //dp[j][i] = global_min;
            }
        }
        return dp[1][n];
    }
};
