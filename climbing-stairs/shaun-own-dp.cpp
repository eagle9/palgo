/*
runtime 0ms, faster than 100%, mem less than 5% (yet to use rolling array)

cutting: dp,  each time 1 or 2 steps
from dp[n-2], +2 steps
or from dp[n-1], +1 steps
*/
class Solution1 {
public:
    int climbStairs(int n) {
        //n is positive integer
        if (n == 1) return 1;
        if (n == 2) return 2;
        int dp[n+1];
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            //i can be reached 1) dp[i-2] then 2 steps, 
            //or 1 step(1 step overlap with 2)
            //  2) dp[i-1] then 1 step
            dp[i] = dp[i-2] + dp[i-1];
        }
        return dp[n];
    }
};
//with rolling array
//runtime 4ms, faster than 66%, mem less than 76%
class Solution {
public:
    int climbStairs(int n) {
        //n is positive integer
        if (n == 1) return 1;
        if (n == 2) return 2;
        
        int a = 1; //dp[1] = 1;
        int b = 2; //dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            //i can be reached 1) dp[i-2] then 2 steps, 
            //or 1 step(1 step overlap with 2)
            //  2) dp[i-1] then 1 step
            //dp[i] = dp[i-2] + dp[i-1];
            //a b c
            //  a b
            int c = a + b; 
            a = b;         
            b = c;
        }
        //return dp[n];
        return b;
    }
};
