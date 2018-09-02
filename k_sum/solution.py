#adapted from jiadai c++,Your submission beats 97.94% Submissions!
class Solution:
    '''
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return an integer
    '''
    def kSum(self,A, k, target):
        # wirte your code here
        n = len(A)
        #vector<vector<int>> dp(1 + k, vector<int>(1 + target));
        dp = [ [0 for j in range(1 + target)] for i in range(1+k)]
        dp[0][0] = 1

        for i in range(n):
            for j in range(k,0,-1):
                for t in range(target, A[i]-1,-1):
                    dp[j][t] += dp[j - 1][t - A[i]]

        return dp[k][target]
