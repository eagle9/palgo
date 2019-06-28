/*
hua dp idea, cutting angle --> break the string i to j, what's the compute order? 
max of a string, natural to use dp. 
shorter lenth, compute by len

runtime 16ms, faster than 95%, mem less 25%

*/
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size(); //number of balloons
        //according to problem desc, add a value 1 ballon to the head 
        nums.insert(nums.begin(), 1);
        //append a value 1 balloon to the tail
        nums.push_back(1);
        
        //dp[i][j]  value for bursting i to j
        //0 1 2 .... n n+1, so (n+2) * (n+2) for the size
        //final answer will be dp[1][n]
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        
        //transition function, break i---j in all possible ways to
        //break i to j, 2 smaller sequences
        //  i-1  [i ...k-1] k [k+1..j-1   j]  j+1
        
        //init len = 0, for all starting indexes, dp[i][i] = 0, already
        //no extra code here for the len 0 initialization
        
        for (int len = 1; len <= n; ++len) {
            //start from i, end = i + len -1, end <= n
            // i + len - 1 <= n ---> i <= n-len + 1
            for (int i = 1; i <= n - len + 1; ++i) {
                int j = i + len - 1;
                //try all breaks and take the max
                for (int k = i; k <= j; ++k) {
                    dp[i][j] = max(dp[i][j], nums[i - 1] * nums[k] * nums[j + 1] + dp[i][k - 1] + dp[k + 1][j]);
                }
            }
        }
        return dp[1][n];
    }
};

