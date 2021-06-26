//shaun's original idea, accepted after adding some code to deal small value case
//return value for cases that can not enter the loop
//runtime 16ms, faster than 98%
//Memory Usage: 9.8 MB, less than 5.77% 
class Solution1 {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n  = nums.size();
        if (n == 0) return 0; //empty
        vector<int> dp(n); //dp[i] len of longest cis ending at i
        
        dp[0] = 1;
        if (n==1) return dp[0];
        //now n >= 2, can enter the loop
        int res = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i-1] < nums[i]) dp[i] = dp[i-1]+1;
            else dp[i] = 1; //=> reset to 1
            res = max(res, dp[i]);
        }
        
        return res;
    }
};

//shaun try to reduce dp dimension and space usage
//runtime 16ms, faster than 98%, memory less than 35%
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n  = nums.size();
        if (n == 0) return 0; //empty
        //vector<int> dp(n); //dp[i] len of longest cis ending at i
        
        //dp[0] = 1;
        if (n==1) return 1;
        //now n >= 2, can enter the loop
        int res = 0;
        int dp = 1;
        for (int i = 1; i < n; ++i) {
            if (nums[i-1] < nums[i]) dp = dp+1;
            else dp = 1; //=> reset to 1
            res = max(res, dp);
        }
        
        return res;
    }
};
