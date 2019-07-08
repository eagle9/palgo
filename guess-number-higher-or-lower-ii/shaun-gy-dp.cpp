
//http://www.cnblogs.com/grandyang/p/5677550.html
//grandyang dp idea, cutting angle --- cost guessing with longer array recurrence with shorter sub array
//runtime 12ms, faster than 96%, mem less than 82%

class Solution1 {
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

//shaun code computer in the order of array len
//runtime 20ms, faster than 71%, mem less than 76%
//cutting angle --- cost of longer array boils down shorter subarray
//key points: number from 1 to n, compute in the order of len
// make sure index in bound
class Solution {
public:
    int getMoneyAmount(int n) {
        //dp[j][i] stores the money needed from j to i
        //i j range 1 to n --- problem statement, pick a number from 1 to n
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        
        //len == 1, dp[][] = 0, single number to guess, always correct, so the cost is 0
        
        for (int len = 2; len <= n; ++len) {
            //i is the start of sub array, from 1 to n-2
            //for (int i = 0; i <= n-2; ++i) {   //bug 1
            for (int i = 1; i <= n-1 && i + len -1 <= n; ++i) {
                //end index of sub array: i+len-1
                int j = i + len - 1;
                int minij = INT_MAX;
                //split i ...j 
                //k from i+1 to j-1
                for (int k = i + 1; k <= j-1; ++k) { //guess k between j and i
                    //work on the recurrence
                    int local_max = k + max(dp[i][k - 1], dp[k + 1][j]);
                    minij = min(minij, local_max);
                }
                //ij next to each other, i+1 = j case not covered by for k loop
                //but dp[i,i+1] = i, guess with smaller number, i dollars to guanrantee win
                dp[i][j] = i + 1 == j ? i : minij;
                
            }
        }
        return dp[1][n];
    }
};
