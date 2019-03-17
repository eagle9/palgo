//lt dp idea, great idea to come up the recurrence
//shaun in c++
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1); // (size)
        dp[0] = 1;
        dp[1] = 1;
		//for 1 to i, j from 1 to i, j as the root, 1 to j-1 left tree, j+1 to i right tree (i - j-1+1 = i-j) 
		//1     j        i
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                dp[i] += dp[j-1]* dp[i-j];
            }
        }
        return dp[n];
    }
};
