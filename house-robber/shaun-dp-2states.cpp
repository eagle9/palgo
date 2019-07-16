//shaun's own idea with two states at i
//accepted second sub, not focused enough
//runtime 4ms, faster than 100%
class Solution1 {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        
        vector<int> A(n); //A[i] max money from 0 to i with nums[i] taken
        vector<int> B(n); //B[i] max money from 0 to i with nums[i] NOT taken
        
        A[0] = nums[0]; B[0] = 0;
        
        for (int i = 1; i < n; ++i) {
            A[i] = B[i-1] + nums[i]; //cash nums[i] taken by definition, i-1 can not be taken, max from 0 to i-1 is B[i-1]
            
            //now figure out B[i]: max from 0 to i with cash i not taken
            //A[i-1] max from 0 to i-1, i-1 taken, i not taken, so consider A[i-1]
            //other cases: max from 0 to i-1, i-1 not taken, is B[i-1], 
            //so max(A[i-1], B[i-1])
            //B[i] = A[i-1];  //  first submission, but not clear mind
            B[i] = max(A[i-1], B[i-1]);   //cash i not taken, check idea
        }
        return max(A[n-1], B[n-1]);
    }
};

/*
idea:
input array of numbers
take number out of, no adjacent numbers, max the sum
A[i] max money taken from 0 to house i, cash at i taken
B[i] max money from 0 to i, cash at i not taken
A[i] = max(A[i-1], B[i-1]+a[i])
B[i] = max(A[i-1], B[i-1])

another idea
 i-2     i-1    i
dp[i]  taken  dp[i-2]
       not taen dp[i-1]
*/

//runtime 4ms, faster than 100%
class Solution2 {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        vector<int> dp(n); //dp[i] max sum from 0 to i
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; ++i) {
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
        }
        return dp[n-1];
    }
};

//reduce dimension, runtime 4ms, faster than 100%
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        int dp0 = nums[0];
        int dp1 = max(nums[0], nums[1]);
        for (int i = 2; i < n; ++i) {
            int dp2 = max(dp0 + nums[i], dp1);
            dp0 = dp1;
            dp1 = dp2;
        }
        return dp1;
    }
};
