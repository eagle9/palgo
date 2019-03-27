//shaun first try, using backtracking, first sub wrong answer
//removed used vector, correct output for specific test case, TLE
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        //vector<bool> used(n);
        vector<int> cur;
        int res = 0;
        helper(nums, target, 0, cur, res);
        return res;
    }
    
private:
    void helper(vector<int>& nums, int target, int curSum, vector<int>& cur, int& res) {
        if (curSum >= target){ //added > to make sure recursion exit
			if (curSum == target)
            	res++;
            return;
        }

        //take 1 number from nums 
        for (int i = 0; i < nums.size(); i++) {
            cur.push_back(nums[i]);
            curSum += nums[i];
            
            helper(nums, target, curSum, cur, res);
            cur.pop_back();
            curSum -= nums[i];
        }
    }
};


/*
idea forming
take 1 number from nums, grow curSum till >= target 
how to transition to DP? 
nums 0--i  make target 0 .. j  dp[i][j] number of combis
nums 0 .. i+1, target 0 .. j+1 
0-0
for (int j = 0; j <= target; ++j) { 
	if (j % nums[0] == 0)  
		dp[0][j] = 1;
	else 
		dp[0][j] = 0;
}
for (int i = 0; i < nums.size(); ++i) {
	//using nums all positive to make target = 0
	dp[i][0] = 0;
}
for (int i = 0; i < nums.size(); ++i) {
	for (int j = 0; j <= target; ++j) {
		dp[i][j] =   dp[i-1][j];
		int remain = j;
		while (remain - nums[i]>=0) {
			dp[i][j] +=   dp[i-1][remain - nums[i]];
			remain -= nums[i];	
		}
	}
}
                
             take nums[i] 1 or more times         no take nums[i]

return dp[n-1][target]

*/
