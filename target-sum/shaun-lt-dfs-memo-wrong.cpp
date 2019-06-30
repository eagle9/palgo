//shaun rewrite lt's dfs with memo
//wrong answer
class Solution {
    int count = 0;
public:
    
    int findTargetSumWays(vector<int>& nums, int S) {
        vector<vector<int>> memo(nums.size(), vector<int>(2001, INT_MIN));
        //return helper(nums, 0, 0, S, memo);
        helper(nums, 0, 0, S, memo);
        return count;
    }
private:
    int helper1(vector<int>& nums, int pos, int sum, int target, vector<vector<int>>& memo) {
        if (pos == nums.size()) {
            if (sum == target) return 1;
            else return 0;
            
        }
        //the reason to add 1000 is to ensure it is positive, since sum is in range [-1000, 1000]
        if (memo[pos][sum + 1000] != INT_MIN) return memo[pos][sum+1000];
        int add     = helper1(nums, pos+1, sum+nums[pos], target, memo);
        int subtract= helper1(nums, pos+1, sum-nums[pos], target, memo);
        return memo[pos][sum + 1000] = add + subtract;
    }
    
    void helper(vector<int>& nums, int pos, int sum, int target, vector<vector<int>>& memo) {
        if (pos == nums.size()) {
            if (sum == target) count++;
            return;
        }
        //the reason to add 1000 is to ensure it is positive, since sum is in range [-1000, 1000]
        if (memo[pos][sum + 1000] != INT_MIN) return;
        helper(nums, pos+1, sum+nums[pos], target, memo);
        helper(nums, pos+1, sum-nums[pos], target, memo);
        memo[pos][sum + 1000] = 1;
    }
};


